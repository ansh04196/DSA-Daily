class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        
string temp = s + "#" + string(s.rbegin(), s.rend());
        
       
        int n = temp.size();
        vector<int> lps(n, 0);
        int j = 0;
        
        for (int i = 1; i < n; i++) {
            if (temp[i] == temp[j]) {
                j++;
                lps[i] = j;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                    i--; 
                } else {
                    lps[i] = 0;
                }
            }
        }
        
  return s.size() - lps[n - 1];
    }
};
