
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int> last(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        
        int end=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            end = max(end, last[s[i]-'a']);
            if(i==end){
                cnt++;
            }
        }
        return cnt;
    }
};


//GFG POTD solution for 31 March
