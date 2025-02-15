/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(!root)
            return NULL;
            
        if(root->data==n1->data || root->data==n2->data)
            return root;
        
        Node* left  = LCA(root->left , n1, n2);
        Node* right = LCA(root->right, n1, n2);
        
        if(left && right) {
            return root;
        }
        
        if(left)
            return left;
        
        else
            return right;
    }
};


//GFG POTD solution for 15 February
