class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> set;
        for (int i : nums){
            if (set.count(i)) res.push_back(i);
            else set.insert(i);
        }
        return res;
    }
};
