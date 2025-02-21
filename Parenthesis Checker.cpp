class Solution {
  public:
    bool isBalanced(string& s) {
           stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
