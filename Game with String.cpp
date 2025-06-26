class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        for(auto x : s){
            mp[x]++;
        }
        priority_queue<int> pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k && !pq.empty()){
            int a = pq.top();
            pq.pop();
            a -= 1;
            k -= 1;
            if(a != 0){
                pq.push(a);
            }
        }
        
        int sum = 0 ;
        while(!pq.empty()){
            int sq = pq.top();
            sum += sq*sq;
            pq.pop();
        }
        return sum;
    }
};
//GFG POTD solution for 26 June
