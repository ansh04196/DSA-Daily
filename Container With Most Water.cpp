class Solution {
  public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        int l = 0;      
        int r = n - 1; 
        int area = 0;

        while (l < r) {
             area = max(area, min(arr[l], arr[r]) * (r - l));

             if (arr[l] < arr[r])
                l += 1;
            else
                r -= 1;
        }
        return area;
    }
};
