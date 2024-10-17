class Solution {
public:
    int getSingle(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        
        for (int num : arr) {
            freqMap[num]++;
        }
        
        for (auto& pair : freqMap) {
            if (pair.second % 2 != 0) {
                return pair.first;
            }
        }
        
        return -1;
    }
};
