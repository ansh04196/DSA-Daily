lass Solution{
    public:
    // Function to find the single element in the array
    int findSingle(int n, int arr[]){
        int ans = 0;
        
        // loop to find the single element
        for(int i = 0;i < n;i++){
            ans ^= arr[i];
        }
        return ans;
    }
};
