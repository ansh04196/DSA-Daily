class Solution
{
    public:
        // Function to calculate the sum of leaf nodes
        int sumOfLeafNodes(Node *root){
            // If the node is empty, return 0
            if (root == NULL) return 0;
        
            // If the node has no children, return its data
            if (root->left == NULL && root->right == NULL)
                return root->data;
        
            // Recursive call to calculate the sum of leaf nodes in the left and right subtrees
            return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
        }
};
