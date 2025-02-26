

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        stack<int> s1;
        int n = arr.size();
        vector<int> left(n+1, -1);
        vector<int> right(n+1, n);
        
        for(int i=0;i<n;i++) {
            while(!s1.empty() && arr[s1.top()]>=arr[i])
                s1.pop();
            if(!s1.empty())
                left[i] = s1.top();
            s1.push(i);
        }
        
        while(!s1.empty())
            s1.pop();
            
        for(int i=n-1;i>=0;i--) {
            while(!s1.empty() && arr[s1.top()]>=arr[i])
                s1.pop();
            if(!s1.empty())
                right[i] = s1.top();
            s1.push(i);
        }
        
        vector<int> result(n+1, 0);
        for(int i=0;i<n;i++) {
            int len = right[i]-left[i]-1;
            result[len] = max(result[len], arr[i]);
        }
        
        for(int i=n-1;i>=0;i--) {
            result[i] = max(result[i], result[i+1]);
        }
        
        vector<int> finalResult(n);
        for(int i=1;i<=n;i++) {
            finalResult[i-1] = result[i];
        }
        
        return finalResult;
    }
};


//GFG POTD solution for 26 February
