class Solution {
public:
    vector<int> bracketNumbers(string& str) {
        // Your code goes here
        int op=0;
        vector<int> v;
        stack<int> st;
        for(auto& c:str) {
            if(c=='(') {
                op++;
                st.push(op);
                v.push_back(op);
            }
            else if(c==')') {
                v.push_back(st. top());
                st.pop();
            }
        }
        return v;
    }
};
