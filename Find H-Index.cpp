class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        vector<int> citationBuckets(papers + 1, 0);

        // Counting the number of papers in each citation bucket
        for (int citation : citations) {
            citationBuckets[min(citation, papers)]++;
        }

        int cumulativePapers = 0;
        // Iterating from highest h-index to lowest
        for (int hIndex = papers; hIndex >= 0; hIndex--) {
            cumulativePapers += citationBuckets[hIndex];
            // Checking if current h-index is satisfied
            if (cumulativePapers >= hIndex) {
                return hIndex;
            }
        }
        return 0; // Return 0 if no h-index is found
    }
};
