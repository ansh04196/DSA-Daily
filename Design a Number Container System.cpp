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
    vector<int> res;
    void left(Node * root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        res.push_back(root->data);
        
        if(root->left) left(root->left);
        else left(root->right);
    }
    
    void leaf(Node * root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(root->data);
            return;
        } 
        leaf(root->left);
        leaf(root->right);
    }
    
    void right(Node * root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        if(root->right) right(root->right);
        else right(root->left);
        
        res.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
       res.push_back(root->data);
       
       if(root->left == nullptr && root->right == nullptr) return res;
       
       left(root->left);
       leaf(root);
       right(root->right);
       
       return res;
    }
};



// 1 2 5 3







//GFG POTD solution for 08 February
