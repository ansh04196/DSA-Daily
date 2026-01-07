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
    long long totalSum = 0;
    long long best = 0;

    long long dfsSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }
    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long sum = root->val + dfs(root->left) + dfs(root->right);
        best = max(best, sum * (totalSum - sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        totalSum = dfsSum(root);  // 1st pass: compute total sum
        dfs(root);                // 2nd pass: compute best split
        return best % MOD;
    }
};
