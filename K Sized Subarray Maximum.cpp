
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>res;
        
       priority_queue<pair<int , int>>pq;
       
       for(int i=0;i<k;i++) pq.push({arr[i] , i});
       
       res.push_back(pq.top().first);
       
       
       for(int i=k;i<n;i++){
           pq.push({arr[i] , i});
           
           while(pq.top().second<=i-k) pq.pop();
           
           res.push_back(pq.top().first);
       }
       
       return res;
    }
};


//GFG POTD solution for 02 March
