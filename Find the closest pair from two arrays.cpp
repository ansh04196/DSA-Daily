class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        int diff = INT_MAX;
        int ele1 = -1,ele2 = -1;
        int i = 0,j = m - 1;
        while(i < n && j >= 0){
            int sum = arr1[i] + arr2[j];
            
            if(abs(sum - x) < diff){
                diff = abs(sum - x);
                ele1 = arr1[i];
                ele2 = arr2[j];
            }
            
            if(sum < x)
                i++;
            else if(sum > x)
                j--;
            else
                break;
        }
        return {ele1,ele2};
    }
};
//GFG POTD solution for 28 February
