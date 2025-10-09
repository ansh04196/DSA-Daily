class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> free(n + 1, 0);
        for (int j = 0; j < m; j++){
            for (int i = 0; i < n; i++){
                free[i + 1] = max(free[i], free[i + 1]) + (1LL * skill[i] * mana[j]);
            }
            // Remove waiting time for synchronisation of potion passing
            for (int i = n - 1; i > 0; i--){
                free[i] = free[i + 1] - (1LL * skill[i] * mana[j]);
            }
        }
        return free[n];
    }
};
