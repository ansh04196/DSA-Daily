class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size(), n = trainers.size(), res = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        for (int i = 0, j = 0; i < m && j < n; j++, i++){
            while(j < n && i < m && players[i] > trainers[j]) j++;
            res += j < n;
        }
        return res;
    }
};
