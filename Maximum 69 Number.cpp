class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for (char &c : str){
            if (c == '6'){
                c = '9';
                break;
            }
        }
        return stoi(str);
    }
};
