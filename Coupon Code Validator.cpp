class Solution {
public:
    bool validateCode(string s){
        bool flag = true;
        for (char ch : s){
            if (ch >= '0' && ch <= '9') continue;
            if (ch >= 'A' && ch <= 'Z') continue;
            if (ch >= 'a' && ch <= 'z') continue;
            if (ch == '_') continue;
            flag = false;
        }
        return !s.empty() && flag;
    }
    bool validateLine(string s){
        return (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> res;
        map<string, vector<string>> lines;
        for (int i = 0; i < n; i++){
            if (isActive[i] && validateCode(code[i]) && validateLine(businessLine[i])) 
                lines[businessLine[i]].push_back(code[i]);
        }
        for (auto &it : lines){
            sort(it.second.begin(), it.second.end());
            for (string str : it.second) res.push_back(str);
        }
        return res;
    }
};
