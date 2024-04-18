 class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[],  
                 int n, int m) 
	{ 
	    
	    unordered_set <int> s;
	    vector<int> ans;
	    for (int i = 0; i < m; i++) 
	        s.insert(b[i]); 
	  
	    
	    for (int i = 0; i < n; i++) 
	        if (s.find(a[i]) == s.end()) 
	            ans.push_back(a[i]);
	    return ans;
	} 
};
