class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n= arr.size();
        int k=1;
        while(n>1){
            int last = arr.back();
            arr.pop_back();
            arr.insert(arr.begin(),last);
            int deleteIndex = n-k;
            if (deleteIndex<0){
                deleteIndex=0;
            }
            arr.erase(arr.begin() + deleteIndex);
            n--;
            k++;
        }
        return arr[0];
    }
};
