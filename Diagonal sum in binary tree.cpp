class Solution
{
    public:
    // root - root of the binary tree 
    // vd - vertical distance diagonally 
    // diagonalSum - map to store Diagonal  
    // Sum(Passed by Reference) 
    void diagonalSumUtil(struct Node* root, 
                    int vd, map<int, int> &diagonalSum) 
    { 
        if(!root) 
            return; 
              
        diagonalSum[vd] += root->data; 
      
        // increase the vertical distance if left child 
        diagonalSumUtil(root->left, vd + 1, diagonalSum); 
      
        // vertical distance remains same for right child 
        diagonalSumUtil(root->right, vd, diagonalSum); 
    } 
      
    // Function to calculate diagonal  
    // sum of given binary tree 
    vector <int> diagonalSum(struct Node* root) 
    { 
        vector <int> res;
        // create a map to store Diagonal Sum 
        map<int, int> diagonalSum;  
          
        diagonalSumUtil(root, 0, diagonalSum); 
      
        map<int, int>::iterator it; 
          
        for(it = diagonalSum.begin(); 
                    it != diagonalSum.end(); ++it) 
        { 
            res.push_back (it->second);
        } 
        return res;
    } 
};
