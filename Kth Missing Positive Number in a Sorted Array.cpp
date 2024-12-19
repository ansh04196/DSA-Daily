class Solution {
    public int kthMissing(int[] arr, int k) {
        int n = arr.length;
        int left = 0, right = n-1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int numbers = arr[mid] - mid - 1;
            
            if(numbers < k)
            {
                left = mid + 1;
            }        
            else
                right = mid - 1;
        }
            
        return left == n ? k + right + 1 : left + k;
    }
}
