class Solution {
  public:
    // Function to find overlapping arr and merge them.
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;

        // if there are no arr, return empty result.
        if (arr.size() == 0)
            return ans;

        // sorting arr based on their starting points.
        sort(arr.begin(), arr.end());

        int l = arr[0][0]; // initialize left end of first interval
        int r = arr[0][1]; // initialize right end of first interval

        // iterating over arr starting from 1
        for (int i = 1; i < arr.size(); i++) {
            // if current interval overlaps with the previous interval
            if (arr[i][0] <= r)
                r = max(r, arr[i][1]); // update right end

            // if current interval does not overlap with the previous interval
            else {
                // add the previous interval to result
                ans.push_back({l, r});

                // update left and right end for the current interval
                l = arr[i][0];
                r = arr[i][1];
            }
        }

        // add the last interval to result
        ans.push_back({l, r});

        // return the merged arr
        return ans;
    }
};
