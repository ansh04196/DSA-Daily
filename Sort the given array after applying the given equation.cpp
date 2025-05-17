
class Solution {
  public:
    
    int tf(int A, int B, int C, int x){
        return A*(x*x) + B*x + C;
    }
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr[i] = tf(A,B,C,arr[i]);
        }
        vector<int> ans(n);
        //min values at the end points of array.
        if(A<0){
            int left = 0, right = n-1;
            int i=0;
            while(left<=right && i<n){
                if(arr[left]<arr[right]){
                    ans[i] = arr[left];
                    left++;
                    
                }
                else {
                    ans[i] = arr[right];
                    right--;
                }
                i++;
            }
        }
        else{
            int left = 0, right = n-1;
            int i=n-1;
            while(left<=right && i>=0){
                if(arr[left]>arr[right]){
                    ans[i] = arr[left];
                    left++;
                    
                }
                else {
                    ans[i] = arr[right];
                    right--;
                }
                i--;
            }
            
        }
        return ans;
    }
};


//GFG POTD solution for 17 May
