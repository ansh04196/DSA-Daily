class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.size();
	    int n = str2.size();
	    
	    int L[m+1][n+1]; 
	   	int i, j; 
	    
 
	   	for (i=0; i<=m; i++) 
	   	{ 
	     	for (j=0; j<=n; j++) 
	     	{	 
	      		if (i == 0 || j == 0) 
	         		L[i][j] = 0; 
	    
	       		else if (str1.at(i-1) == str2.at(j-1)) 
	         		L[i][j] = L[i-1][j-1] + 1; 
	    
	       		else
	         		L[i][j] = max(L[i-1][j], L[i][j-1]); 
	     	} 
	   	} 
	      
 
	   	return m + n - 2*L[m][n];
	} 
};
