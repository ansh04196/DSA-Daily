// Full function Template for C++
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* fN = q.front();
            q.pop();
            
            if(fN->left || fN->right){
                Node* temp = fN->left;
                fN->left = fN->right;
                fN->right = temp;
            
                if(fN->left)
                    q.push(fN->left);
                if(fN->right)
                    q.push(fN->right);
            }
            
        }
        
        return;   
    }
};


//GFG POTD solution for 05 February
