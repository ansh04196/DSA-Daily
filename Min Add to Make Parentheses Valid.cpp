class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char> st;
        
        int count =0;
        
        for(char ch : s){
            if(ch == '(') st.push(ch);
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    count++;
                }
            }
        }
        
        count+=st.size();
        
        return count;
    }
};
//GFG POTD solution for 19 September
