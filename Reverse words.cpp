class Solution {
  public:
     string reverseWords(string str) {
        string result = "";
        string curr_word = "";
        vector<string> words;

         for (int i = 0; i < str.length(); ++i) {
             if (str[i] == '.') {
                words.push_back(curr_word);
                curr_word = "";
            }
         
            else
                curr_word += str[i];
        }
         words.push_back(curr_word);

       
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i != 0)
                result += '.';
        }
         return result;
    }
};
