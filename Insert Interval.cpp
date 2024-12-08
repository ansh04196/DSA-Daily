class Solution {
  public:
    // Function to insert a new event into a list of intervals.
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newEvent) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;

        // Adding intervals that end before the new event starts.
        while (i < n && intervals[i][1] < newEvent[0])
            res.push_back(intervals[i++]);

        // Merging intervals that overlap with the new event.
        while (i < n && newEvent[1] >= intervals[i][0]) {
            newEvent[0] = min(newEvent[0], intervals[i][0]);
            newEvent[1] = max(newEvent[1], intervals[i][1]);
            i++;
        }

        // Adding the new merged event.
        res.push_back(newEvent);

        // Adding remaining intervals.
        while (i < n)
            res.push_back(intervals[i++]);

        // Returning the resulting list of intervals.
        return res;
    }
};
