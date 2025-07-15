class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool invalidChar(char ch){
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))) return true;
        return false;
    }
    bool isValid(string word) {
        int n = word.size(), vowel = 0, consonant = 0;
        if (n < 3) return false;
        for (char ch : word){
            if (invalidChar(ch)) return false;
            if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) continue;
            if (isVowel(ch)) vowel = 1;
            else consonant = 1;
        }
        return vowel && consonant;
    }
};
