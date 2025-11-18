class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count = 0;
        while (count < bits.size() - 1) count += bits[count] + 1;
        return count == bits.size() - 1;
    }
};
