class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int start = 0, end = 0;
        vector<int> result;
        int curr= 0;
        for(int i = 0 ; i < arr.size();i++)
        {
            curr += arr[i];
            if(curr >= target)
            {
                end = i;
            }
            
            while(curr > target && start < end)
            {
                curr -= arr[start];
                ++start;
            }
            
            if(curr == target)
            {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            }
        }
        
        return {-1};
    }
};
