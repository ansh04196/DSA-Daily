

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int ch=0;
        for(int i=0;i<n;i++){
            ch+=(gas[i]-cost[i]);
        }
        if(ch<0)
            return -1;
        int idx=0;
        int rem=0;
        for(int i=0;i<n;i++){
            rem+=(gas[i]-cost[i]);
            if(rem<0){
                idx=i+1;
                rem=0;
            }
        }
        return idx;
    }
};



//GFG POTD solution for 30 March
