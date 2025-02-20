class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medians;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : arr) {
            maxHeap.push(num);
            if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if (maxHeap.size() > minHeap.size())
                medians.push_back(maxHeap.top());
            else
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        }
        return medians;
    }
};


//GFG POTD solution for 20 February
