class Solution {
  public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
        || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        }
        
        return false;
    }
    
    int fact(int n)
    {
        if(n==0) return 0;
        int f=1;
        
        for(int i=1;i<=n;i++)
        {
            f*=i;
        }
        return f;
    }
    int vowelCount(string& s) {
        // code here
        unordered_map<int,int>mp;
        int n=s.size();
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                mp[s[i]]++;
            }
        }
        
        int vow=1;
        for(auto it:mp)
        {
            vow*=it.second;
        }
        return vow*fact(mp.size());
    }
};
//GFG POTD solution for 19 July
