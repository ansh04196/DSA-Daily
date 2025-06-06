
class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
          // Your code here
          // Handle empty strings
        if (s1.empty() || s2.empty()) return "0";
        
        // Handle signs
        bool negative = false;
        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }

        // Remove leading zeros
        s1.erase(0, s1.find_first_not_of('0'));
        s2.erase(0, s2.find_first_not_of('0'));
        
        if (s1.empty() || s2.empty()) return "0"; // One of them was zero

        int n = s1.size(), m = s2.size();
        vector<int> res(n + m, 0);

        // Multiply each digit
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + res[i + j + 1];
                
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        // Build result string
        string result;
        int i = 0;
        while (i < res.size() && res[i] == 0) ++i; // skip leading zeros
        for (; i < res.size(); ++i) {
            result.push_back(res[i] + '0');
        }

        if (result.empty()) return "0"; // in case result was all zeros

        // Add negative sign if needed
        if (negative) {
            result = "-" + result;
        }
        return result;
    }
};


//GFG POTD solution for 27 April
