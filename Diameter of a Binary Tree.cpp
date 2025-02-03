/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  
    int fun(Node* root,int* height){
        
        if(root == NULL)
            return 0;
            
        int left = fun(root->left, height);
        int right = fun(root->right, height);
        
        int dai = left + right ;
        
        if(dai > *height)
            *height = dai;
            
        return max(left, right) + 1;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        int height = 0;
        fun(root, &height);
        
        return height;
    }
};

//GFG POTD solution for 04 February
