class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        sort(arr.begin(), arr.end(), greater<int>());
        int n=arr.at(0);
        for(int i=1;i<arr.size();i++){
            if(arr.at(i)==n){
                n=arr.at(i);
                continue;
            }
            else if(arr.at(i)<n){
                n=arr.at(i);
                return n;
            }
        }
        return -1;
    }
};
