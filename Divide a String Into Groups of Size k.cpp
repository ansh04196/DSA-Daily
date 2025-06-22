class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size(), i = 0;
        vector<string> res;
        while(i < n){
            int curr = k;
            string str;
            while(i < n && curr) str += s[i++], curr--;
            while (curr) str += fill, curr--;
            res.push_back(str);
        }
        return res;
    }
};
