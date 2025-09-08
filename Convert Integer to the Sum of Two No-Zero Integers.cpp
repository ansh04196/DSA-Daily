class Solution {
public:
    bool hasZero(int n){
        bool flag = false;
        while(n){
            flag |= !(n % 10);
            n /= 10;
        }
        return flag;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++){
            if (!hasZero(i) && !hasZero(n - i)) return {i, n - i};
        }
        return {};
    }
};
