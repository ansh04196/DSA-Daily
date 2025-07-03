class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            string temp = "";
            for (int i = 0; i < s.size(); i++) temp += ('a' + (((s[i] - 'a') + 1) % 26));
            s += temp;
        }
        return s[k - 1];
    }
};
