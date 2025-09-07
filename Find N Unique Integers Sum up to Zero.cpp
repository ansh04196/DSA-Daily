class Solution {
public:
    vector<int> sumZero(int n) {
        int temp = n;
        vector<int> res(n, 0);
        for (int i = 0; i < n / 2; i++){
            res[i] = temp;
            res[n - i - 1] = -1 * temp;
            temp--;
        }
        return res;
    }
};
