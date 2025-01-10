class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
       vector<int> res;
        map<int,int> mp;
        for(int i=0;i<k;i++) {
            mp[arr[i]]++;
        }
        res.push_back(mp.size());
        int n = arr.size();
        for(int i=1;i<=n-k;i++) {
            mp[arr[i-1]]--;
            if(mp[arr[i-1]] == 0) {
                mp.erase(arr[i-1]);
            }
            mp[arr[i+k-1]]++;
            res.push_back(mp.size());
        }
        return res;
    }
};
