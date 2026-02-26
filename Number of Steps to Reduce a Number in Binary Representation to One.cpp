class Solution {
public:
    void addOne(string &s){
        int n = s.size();
        int carry = 1;  // we start with a carry of 1, representing the addition of 1
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                s[i] = '0';  // 1+1=0 (carry remains 1)
            } else {
                s[i] = '1';  // 0+1=1 (carry becomes 0)
                carry = 0;
                break;
            }
        }
        if (carry) {
            s.insert(s.begin(), '1');
        }
    }
    int numSteps(string s) {
        int res = 0;
        while (s != "1"){
            if (s.back() == '1') addOne(s);
            else s.pop_back();  // Removing the last character since dividing by 2 in binary shifts right by 1 bit
            res++;
        }
        return res;
    }
};
