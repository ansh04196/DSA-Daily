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
    int maxLevelSum(TreeNode* root) {
        int res = 1, maxi = root->val, sum = 0, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if (!node){
                if (!q.empty()) q.push(nullptr);
                if (sum > maxi) maxi = sum, res = level;
                level++;
                sum = 0;
            }
            else{
                sum += node->val;
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return res;
    }
};
