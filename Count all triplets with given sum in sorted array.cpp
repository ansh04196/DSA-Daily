class Solution {
  public:
    int countTriplets(vector<int> &array, int target) {
        // Code Here
        sort(array.begin(), array.end());
        int output=0;
        int n=array.size();
        for(int i=0; i<n; i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                if(array[i]+array[start]+array[end]==target){
                    if(array[start]==array[end]){
                        int number=end-start+1;
                        output+=(number*(number-1))/2;
                        start=n;
                    }
                    else{
                        int value=array[start];
                        int a=0;
                        while(array[start]==value){
                            a++;
                            start++;
                        }
                        value=array[end];
                        int b=0;
                        while(array[end]==value){
                            end--;
                            b++;
                        }
                        output+=a*b;
                    }
                }
                else if(array[i]+array[start]+array[end]>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return output;
    }
};
