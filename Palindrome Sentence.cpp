class Solution {
  public:
    bool isPalinSent(string &s) {
        int i = 0, j = s.size() - 1;
        
        while (i <= j) {
            // Skip non-alphanumeric characters
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            
            // Compare lowercase versions
            if (tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};

//GFG POTD solution for 05 August
