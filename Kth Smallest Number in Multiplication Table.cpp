class Solution
{
public:
    int kthSmallest(int m, int n, int k)
    {
        int low = 1, high = m * n, mid, cnt;
        while (low < high)
        {
            cnt = 0;
            mid = low + (high - low) / 2;
            for (int i = 1; i <= m; i++)
            {
                cnt += min(mid / i, n);
            }
            if (cnt >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

//GFG POTD solution for 21 May
