//Back-end complete function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int num = arr.size();
        // implementing MinHeap using priority queue and
        // storing first k elements in it.
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(),
                                                          arr.begin() + k + 1);
        int id = 0;
        for (int i = k + 1; i < num; ++i) {
            // storing top element from priority queue in list and popping it.
            arr[id++] = pq.top();

            pq.pop();

            // pushing the current array element in priority queue.
            pq.push(arr[i]);
        }

        // using a loop till priority queue becomes empty.
        while (!pq.empty()) {
            // storing top element from priority queue in list and popping it.
            arr[id++] = pq.top();
            pq.pop();
        }
    }
};
