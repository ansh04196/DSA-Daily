class Solution {
  public:
    bool hasPathSum(Node *root, int targetSum) {
        // Your code here
        if (root == NULL) return false;
        stack<Node*> st;
        stack<int> sums;
        st.push(root);
        sums.push(root->data);
        while (!st.empty()) {
            Node* node = st.top(); st.pop();
            int sum = sums.top(); sums.pop();
            if (node->left == NULL && node->right == NULL) {
                if (sum == targetSum) return true;
            }
            if (node->left != NULL) {
                st.push(node->left);
                sums.push(sum + node->left->data);
            }
            if (node->right != NULL) {
                st.push(node->right);
                sums.push(sum + node->right->data);
            }
        }
        return false;
    }
};
