struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Ascending by first, descending by second
        if (a.first == b.first)
            return a.second < b.second;  // greater second comes first
        return a.first > b.first;        // smaller first comes first
    }
};
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(int i:arr) {
            if(i==x) {
                continue;
            }
            pq.push({abs(i-x),i});
        }
        vector<int> result;
        while(k--) {
            auto t = pq.top();
            pq.pop();
            result.push_back(t.second);
        }
        return result;
    }
};
//GFG POTD solution for 12 June
