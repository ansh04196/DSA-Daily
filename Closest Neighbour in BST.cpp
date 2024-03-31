class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        if (root == NULL)
            return -1;
        if (root->key == n)
            return n;

        // If root's value is smaller, try in rght
        // subtree
        else if (root->key < n) {
            int k = findMaxForN(root->right, n);
            if (k == -1)
                return root->key;
            else
                return k;
        }

        // If root's key is greater, return value
        // from left subtree.
        else if (root->key > n)
            return findMaxForN(root->left, n);
    }
};
