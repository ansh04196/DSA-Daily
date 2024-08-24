 class Solution {
     static int knapSack(int W, int wt[], int val[]) {
        int i, w;
        int n = wt.length;
        int K[][] = new int[n + 1][W + 1];

         for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {
                 if (i == 0 || w == 0) K[i][w] = 0;

         
                else if (wt[i - 1] <= w)
                    K[i][w] =
                        Math.max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                 else
                    K[i][w] = K[i - 1][w];
            }
        }
         return K[n][W];
    }
}
