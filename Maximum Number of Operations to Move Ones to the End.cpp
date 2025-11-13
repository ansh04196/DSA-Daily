class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(), len = 0, res = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') {
                res += len;
                while(i + 1 < n && s[i + 1] == '0') i++;
            }
            else len++;
        }
        return res;
    }
};
