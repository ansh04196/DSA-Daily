class FindSumPairs {
private:
    vector<int> a, b;
    unordered_map<int, int> map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for (int i : nums2) map[i]++;
    }
    
    void add(int index, int val) {
        map[b[index]]--;
        b[index] += val;
        map[b[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int i : a){
            if (tot >= i) res += map[tot - i];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
