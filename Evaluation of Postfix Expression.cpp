class Solution {
  public:
    int evaluate(vector<string>& arr) {
         stack<int> st;

     for (string token : arr) {
        
        
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
        } 
        
         else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
    }
};

