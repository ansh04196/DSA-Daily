class Solution{
		

	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Create 2D Matrix that stores dot product 
	    // dp[i+1][j+1] stores product considering b[0..i] 
	    // and a[0...j]. Note that since all m > n, we fill 
	    // values in upper diagonal of dp[][] 
	    int dp[m+1][n+1]; 
	    memset(dp, 0, sizeof(dp)); 
	  
	    // Traverse through all elements of B[] 
	    for (int i=1; i<=m; i++) 
	  
	        // Consider all values of a[] with indexes greater 
	        // than or equal to i and compute dp[i][j] 
	        for (int j=i; j<=n; j++) 
	  
	            // Two cases arise 
	            // 1) Include a[j] 
	            // 2) Exclude a[j] (insert 0 in b[])  
	            dp[i][j] = max((dp[i-1][j-1] + (a[j-1]*b[i-1])) , 
	                            dp[i][j-1]); 
	  
	    // return Maximum Dot Product 
	    return dp[m][n] ; 
	} 
};
