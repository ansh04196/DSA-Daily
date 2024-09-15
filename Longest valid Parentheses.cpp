class Solution {
  public:
     int maxLength(string str) {
        int ind = -1, maxi = 0;
        stack<int> st;

         for (int i = 0; i < str.size(); i++) {
             if (str[i] == '(')
                st.push(i);
            else {
                
                if (!st.empty()) {
                    st.pop();

                    
                    if (!st.empty())
                    
                    else
                        maxi = max(maxi, i - ind);
                }
                 else
                    ind = i;
            }
        }
         return maxi;
    }
};
