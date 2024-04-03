class Solution
{
    public:
    Node* LCA(Node *root, int x, int y)
    {
        // base case
        if(root==NULL)
            return NULL;
        
        //If both x and y are smaller than data at current node, we call 
        //the function recursively for finding LCA in the left subtree. 
        if(x<root->data and y<root->data)
        {
            return LCA(root->left,x,y);
        }
        //If both x and y are greater than data at current node, we call 
        //the function recursively for finding LCA in the right subtree. 
        if(x>root->data and y > root->data)
        {
            return LCA(root->right,x,y);
        }
        
        //returning the lowest common ancestor.
        return root;
    }
    
    void pathToNode(Node *root, Node *node, vector<int>&path)
    {
        path.push_back(root->data);
        if(root->data==node->data)
            return;
        else if(node->data>root->data)
            pathToNode(root->right,node,path);
        else
            pathToNode(root->left,node,path);
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        Node *lca=LCA(root,x,y);
        vector<int>path;
        pathToNode(root,lca,path);
        reverse(path.begin(),path.end());
        if(path.size()<k)
            return -1;
        return path[k-1];
    }
};
