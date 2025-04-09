class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> pq;
        for (int i : nums) {
            map[i]++;
            if (i < k) return -1;
        }
        for (auto it : map) pq.push({it.first, it.second});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if (!pq.empty()){
                auto temp1 = pq.top();
                pq.pop();
                temp1.second += temp.second;
                res++;
                if (temp1.first == k) return res;
                pq.push(temp1);
            }
        }
        if (mini == maxi && k == mini) return 0;
        return res + 1;
    }
};
