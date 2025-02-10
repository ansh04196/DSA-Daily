/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void findSum(Node* root, int k, vector<int> &path,int & count)
    {
        if(!root)
            return;
        path.push_back(root->data);
        findSum(root->left,k,path,count);
        findSum(root->right,k,path,count);
        int sum=0;
         for(int i=path.size()-1;i>=0;--i){

          sum+=path[i];

          if(sum==k) count++;

       }
        
        path.pop_back();
    }
    int sumK(Node *root, int k) {
        // code here
        
        int count=0;
        vector<int> ans;
        findSum(root,k,ans,count);
        return count;
        
    }
};

//GFG POTD solution for 10 February
