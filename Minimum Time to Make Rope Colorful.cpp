class Solution {
public:
    int minCost(string colors, vector<int>& neededTime){
        int last = 0, cost = 0;
        for (int i = 1; i < colors.size(); i++){
            if (colors[i] != colors[last]) last = i;
            else{
                if (neededTime[i] > neededTime[last]) cost += neededTime[last], last = i;
                else cost += neededTime[i];
            }
        }
        return cost;
    }
};
