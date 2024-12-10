class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int i=a.size()-1,j=0;
        while(j<b.size() && i>=0){
            if(a[i]>b[j]){
                swap(a[i],b[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};
