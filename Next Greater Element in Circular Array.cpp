class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1); // result array initially -1 se bhara
        stack<int> st; // stack indices ko store karega
        
        // circular array handle karne ke liye 2n-1 tak loop
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n; // circular index
            
            // jab tak stack empty na ho aur current element ke barabar ya chhota ho
            // pop karte raho (kyunki wo NGE nahi ban sakte)
            while (!st.empty() && arr[st.top()] <= arr[idx]) {
                st.pop();
            }
            
            // agar stack empty nahi hai to top element hi next greater hoga
            if (!st.empty()) {
                res[idx] = arr[st.top()];
            }
            
            // current index ko stack me daalo future ke elements ke liye
            st.push(idx);
        }
        
        return res;
    }
};

//GFG POTD solution for 18 September
