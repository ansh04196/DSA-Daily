class Solution
{
public:
    void inorder(Node *curr, Node *&prev)
    {
        // Base case
        if (curr == NULL)
            return;
        inorder(curr->left, prev);
        prev->left = NULL;
        prev->right = curr;
        prev = curr;
        inorder(curr->right, prev);
    }
    Node *flattenBST(Node *root)
    {
        // Dummy node
        Node *dummy = new Node(-1);

        // Pointer to previous element
        Node *prev = dummy;

        // Calling in-order traversal
        inorder(root, prev);

        prev->left = NULL;
        prev->right = NULL;
        Node *ret = dummy->right;

        // Delete dummy node
        delete dummy;
        return ret;
    }
};
