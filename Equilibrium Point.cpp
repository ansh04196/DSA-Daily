class Solution {
  public:
     int findEquilibrium(vector<int> &arr) {
         int total=0;
      for(int i=0; i<arr.size(); i++){
          total+=arr[i];
      }
      int pre=0;
      
      for(int pvt=0; pvt<arr.size(); pvt++){
          int ss=total-pre-arr[pvt];
          if(ss==pre){
              return pvt;
          }
          pre+=arr[pvt];
      }
      return -1;
    }
};
