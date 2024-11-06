class Solution {
  public:
    void solve(int& ans, Node* root, int val){
        if (!root) return ;
        val = val*10 + root->data;
        if (!root->left && !root->right){
            ans += val;
        }
        solve(ans, root->left, val);
        solve(ans, root->right, val);
    }
    int treePathsSum(Node *root) {
        int ans = 0;
        solve(ans, root, 0);
        return ans;
    }
};
