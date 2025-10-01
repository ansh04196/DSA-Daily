class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, empty = numBottles;
        while(empty >= numExchange){
            int temp = empty / numExchange;
            int rem = empty % numExchange;
            empty = temp + rem;
            res += temp;
        }
        return res;
    }
};
