
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int count=1;
        int i=1;
        int j=1;
        int end=dep[0];
        while(i<arr.size()){
            if(arr[i]<=end) count++;
            else end=dep[j++];
            i++;
        }
        return count;
    }
};



//GFG POTD solution for 27 March
