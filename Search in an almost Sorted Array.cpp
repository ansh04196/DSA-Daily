
// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // 0 case  // n-1 case
            if(high == low+1) {
                if(arr[low] == target) return low;
                else if(arr[high] == target) return high;
                break;
            }
            // middle case
            else {
                int a = arr[mid-1];
                int b = arr[mid];
                int c = arr[mid+1];
                
                if(a == target) return mid-1;
                else if(b == target) return mid;
                else if(c == target) return mid+1;
                
                
                if((a < b && b < c && b > target) ||
                   (a > b && b < c && a > target) || 
                   (a < b && b > c && c > target))
                {
                        high = mid -1;
                   
                }
                 else low = mid + 1;
            }
        }
        return -1;
    }
};


//GFG POTD solution for 05 May
