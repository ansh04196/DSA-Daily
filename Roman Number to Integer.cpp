class Solution {
public:
    int romanToDecimal(string &s) {
        // Map each Roman numeral to its value
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            // If this numeral is smaller than the next, subtract it
            if (i + 1 < n && value[s[i]] < value[s[i + 1]]) {
                total -= value[s[i]];
            } 
            // Otherwise, add it
            else {
                total += value[s[i]];
            }
        }

        return total;
    }
};

//GFG POTD solution for 06 August
