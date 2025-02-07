class Solution {
  public:
  void ino(Node* root,vector<int> &ans){
      if(root==NULL) return;
      
      ino(root->left,ans);
      ans.push_back(root->data);
      ino(root->right,ans);
      return;
  }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        ino(root,ans);
        return ans;
    }
};
