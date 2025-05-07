
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void fun(Node* root, vector<int> temp,vector<vector<int>> &ans)
    {
        if(root==NULL) return ;
        
        if(root->left==NULL && root->right==NULL)
        {
            temp.push_back(root->data);
            ans.push_back(temp);
            return ;
        }
        temp.push_back(root->data);
        fun(root->left,temp,ans);
        fun(root->right,temp,ans);
        return ;
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(root,temp,ans);
        return ans;
    }
};



//GFG POTD solution for 07 May
