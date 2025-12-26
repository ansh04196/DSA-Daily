class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), curr = 0, res = 0, maxi = 0;
        for (int i = 0; i < n; i++){
            if (customers[i] == 'Y') curr++;
            else curr--;
            if (curr > maxi) maxi = curr, res = i + 1;
        }
        return res;
    }
};
