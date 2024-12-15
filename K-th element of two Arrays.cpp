class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();

        // If a[] has more elements, then call kthElement
        // with reversed parameters
        if (n > m)
            return kthElement(b, a, k);

        // Binary Search on the number of elements we can
        // include in the first set from a[]
        int lo = max(0, k - m), hi = min(k, n);

        while (lo <= hi) {
            int mid1 = (lo + hi) / 2;
            int mid2 = k - mid1;

            // Find elements to the left and right of partition in a[]
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);

            // Find elements to the left and right of partition in b[]
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);

            // If it is a valid partition
            if (l1 <= r2 && l2 <= r1) {

                // Find and return the maximum of l1 and l2
                return max(l1, l2);
            }

            // Check if we need to take lesser elements from a[]
            if (l1 > r2)
                hi = mid1 - 1;

            // Check if we need to take more elements from a[]
            else
                lo = mid1 + 1;
        }

        return 0;
    }
};
