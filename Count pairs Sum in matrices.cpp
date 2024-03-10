class Solution{
public:
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
		// 'r1' and 'c1' for pointing current element 
	    // of mat1[][] 
	    // 'r2' and 'c2' for pointing current element 
	    // of mat2[][] 
	    int r1 = 0, c1 = 0; 
	    int r2 = n - 1, c2 = n - 1; 
	  
	    // While there are more elements 
	    // in both the matrices 
	    int count = 0; 
	    while ((r1 < n) && (r2 >= 0)) { 
	        int val = mat1[r1][c1] + mat2[r2][c2]; 
	  
	        // If true 
	        if (val == x) { 
	  
	            // Increment 'count' 
	            count++; 
	  
	            // Move mat1[][] column 'c1' to right 
	            // Move mat2[][] column 'c2' to left 
	            c1++; 
	            c2--; 
	        } 
	  
	        // If true, move mat1[][] column 'c1' to right 
	        else if (val < x) 
	            c1++; 
	  
	        // Else move mat2[][] column 'c2' to left 
	        else
	            c2--; 
	  
	        // If 'c1' crosses right boundary 
	        if (c1 == n) { 
	  
	            // Reset 'c1' 
	            c1 = 0; 
	  
	            // Increment row 'r1' 
	            r1++; 
	        } 
	  
	        // If 'c2' crosses left boundary 
	        if (c2 == -1) { 
	  
	            // Reset 'c2' 
	            c2 = n - 1; 
	  
	            // Decrement row 'r2' 
	            r2--; 
	        } 
	    } 
	  
	    // Required count of pairs 
	    return count; 
	}
 
};
