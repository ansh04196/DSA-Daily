class Solution {    
    
    int maxProduct(int[] arr) {
    int n=arr.length;
    int sum=1;
    int ans=Integer.MIN_VALUE;
    for(int i=0;i<n;i++){
        int a=arr[i];
        sum*=a;
        ans=Math.max(ans,sum);
        if(sum==0)sum=1;
    }
    sum=1;
    for(int i=n-1;i>=0;i--){
    int a=arr[i];
    sum*=a;
    ans=Math.max(ans,sum);
    if(sum==0)sum=1;
    }   
    return ans;
    }
    
    
}
