class Solution {
public:
    vector<string> extractWords(string text){
        int n = text.size(), i = 0;
        vector<string> res;
        while(i < n){
            string curr = "";
            while(i < n && text[i] != ' ') curr += text[i++];
            res.push_back(curr);
            i++;
        }
        return res;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        vector<string> words = extractWords(text);
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        for (string st: words){
            bool correct = true;
            for (char c : st){
                if (broken.count(c)) correct = false;
            }
            res += correct;
        }
        return res;
    }
};
