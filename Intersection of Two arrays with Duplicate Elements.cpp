class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> ans;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        int last_added = -1;
        while(i<n&& j<m){
            if(a[i]<b[j]){
                i++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else{
                if(last_added!=a[i]){
                    ans.push_back(a[i]);
                    last_added=a[i];
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
