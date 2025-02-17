class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto num: arr){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        reverse(begin(v),end(v));
        return v;
    }
};

//GFG POTD solution for 17 February
