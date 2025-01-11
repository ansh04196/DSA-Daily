class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
          int n=s.size();
        int maxCnt=0;
        int r=0,l=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]==2){
                mp[s[l]]--;
                l++;
            }
            maxCnt=max(maxCnt,r-l+1);
            r++;
        }
        return maxCnt;
    }
};
