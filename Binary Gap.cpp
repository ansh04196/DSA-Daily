class Solution {
public:
    int binaryGap(int n) {
        int res = 0, last = -1;
        for (int i = 0; i < 32; i++){
            if (n & 1){
                if (last != -1) res = max(res, i - last);
                last = i;
            }
            n >>= 1;
        }
        return res;
    }
};
