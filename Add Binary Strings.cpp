class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i] - '0';
            if (j >= 0) sum += s2[j] - '0';
            result += (sum % 2) + '0';
            carry = sum / 2;
            i--;
            j--;
        }
        
        reverse(result.begin(), result.end());
        int pos = result.find_first_not_of('0');
        if (pos == string::npos) {
            return "0";
        } 
        else {
            return result.substr(pos);
        }
    }
};
