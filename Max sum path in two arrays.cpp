class Solution {
 
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        int result = 0, sum1 = 0, sum2 = 0;
        int m = arr1.size(), n = arr2.size();
         while (i < m && j < n) {
             if (arr1[i] < arr2[j])
                sum1 += arr1[i++];
             else if (arr1[i] > arr2[j])
                sum2 += arr2[j++];
              else {
                result += max(sum1, sum2);
                sum1 = 0, sum2 = 0;
                while (i < m && j < n && arr1[i] == arr2[j]) {
                    result = result + arr1[i++];
                    j++;
                }
            }
        }
         while (i < m)
            sum1 += arr1[i++];
         while (j < n)
            sum2 += arr2[j++];

         result += max(sum1, sum2);

        return result;
    }
};
