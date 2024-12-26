class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>s;
        for(int i=0;i<arr.size();i++){
            s.insert({arr[i],i});
        }
        for(int i=0;i<arr.size();i++){
            if(s.find(target-arr[i])!=s.end() && i!=s[target-arr[i]]){
                return true;
            }
        }
        return false;
    }
};
