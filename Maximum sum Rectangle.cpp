class Solution {
  public:
    // Kadane's Algo for 1D
    int kadane(vector<int> &arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }

    // GFG ke Driver ke hisaab se
    int maxRectSum(vector<vector<int>> &M) {
        int R = M.size();
        int C = M[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < C; ++left) {
            vector<int> temp(R, 0);

            for (int right = left; right < C; ++right) {
                for (int i = 0; i < R; ++i)
                    temp[i] += M[i][right];

                maxSum = max(maxSum, kadane(temp));
            }
        }
        return maxSum;
    }
};

//GFG POTD solution for 04 August
