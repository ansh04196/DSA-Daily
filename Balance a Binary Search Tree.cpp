/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderT(TreeNode* root, vector<int> &inorder){
        if (!root) return;
        inorderT(root->left, inorder);
        inorder.push_back(root->val);
        inorderT(root->right, inorder);
    }
    TreeNode* arrange(TreeNode* root, vector<int> &nums, int i, int j){
        if (i > j) return nullptr;
        int mid = i + (j - i) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = arrange(node, nums, i, mid - 1);
        node->right = arrange(node, nums, mid + 1, j);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        vector<int> inorder;
        inorderT(root, inorder);
        return arrange(root, inorder, 0, size(inorder) - 1);
    }
};
