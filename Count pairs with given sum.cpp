class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Brute-force
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(arr[i] + arr[j] == target) count++;
        //     }
        // }
        // return count;
        
        // Optimal Solution
        int n = arr.size();
        unordered_map<int,int>mp;
        
        int count = 0;
        for(int i = 0;i < n;i++){
            if(mp.find(target - arr[i]) != mp.end()) count += mp[target - arr[i]];
            mp[arr[i]]++;
        }
        return count;
    }
};
