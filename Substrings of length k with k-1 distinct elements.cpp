class Solution {
  public:
    int substrCount(string &s, int k) {
        vector<int> freq(26,0);
        int ans=0, distinct=0, l=0;
        for(int r=0;r<s.length();r++){
            if(freq[s[r]-'a']==0) distinct++;
            freq[s[r]-'a']++;
            if(r-l+1>k){ 
                if(freq[s[l]-'a']==1) distinct--;
                freq[s[l]-'a']--;
                l++;
            }
            if(r-l+1==k && distinct==k-1) ans++;
        }
        return ans;
    }
};
//GFG POTD solution for 01 July
