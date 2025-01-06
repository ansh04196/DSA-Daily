class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int,int>mp;
        for(auto x:arr)mp[x]++;
        int count = 0;
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]]--;
            count += mp[(target-arr[i])];
        }
        return count;
    }
};
