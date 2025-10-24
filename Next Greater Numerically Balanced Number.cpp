class Solution {
public:
    bool isBalanced(int x){
        vector<int> freq(10, 0);
        while(x) freq[x % 10]++, x /= 10;
        for (int i = 0; i < 10; i++){
            if (freq[i] && freq[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++){
            if (isBalanced(i)) return i;
        }
        return -1;
    }
};
