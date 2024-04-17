class Solution{
    public:
        int countPairs(int arr[] , int n ) 
    {
        // Your code goes here 
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i*arr[i]);
        }
        vector<int>temp=v;
        sort(temp.begin(),temp.end());
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int x= upper_bound(temp.begin(),temp.end(),v[i])-temp.begin();
            int y=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
            
            ans=ans+(temp.size()-x);
            
            temp.erase(temp.begin()+y);
        }
        return ans;
    }
};
