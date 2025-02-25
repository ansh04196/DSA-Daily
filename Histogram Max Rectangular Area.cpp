class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int maxi=INT_MIN;
        vector<int> nse(n,0);
        vector<int> pse(n,0);
        stack<int> st;
        stack<int> st1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.size()==0){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[i]<=arr[st1.top()]){
                st1.pop();
            }
            if(st1.size()==0){
                nse[i]=n;
            }else{
                nse[i]=st1.top();
            }
            st1.push(i);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};


//GFG POTD solution for 25 February
