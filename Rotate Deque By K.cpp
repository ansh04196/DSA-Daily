class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n = dq.size();
        if (n == 0) return;

        k = k % n; 

        if (type == 1) { 
            for (int i = 0; i < k; i++) {
                int last = dq.back();
                dq.pop_back();
                dq.push_front(last);
            }
        } else if (type == 2) { 
            for (int i = 0; i < k; i++) {
                int first = dq.front();
                dq.pop_front();
                dq.push_back(first);
            }
        }
    }
};
//GFG POTD solution for 26 September
