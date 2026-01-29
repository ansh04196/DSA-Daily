class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        int n = original.size();
        vector<vector<long long>> arr(26, vector<long long> (26, 1e15));
        for (int i = 0; i < n; i++) arr[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i], arr[original[i] - 'a'][changed[i] - 'a']);
        for (int via = 0; via < 26; via++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    if (arr[i][via] != 1e15 && arr[via][j] != 1e15) arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
                }
            }
        }
        for (int i = 0; i < s.size(); i++){
            if (s[i] != t[i]) {
                if (arr[s[i] - 'a'][t[i] - 'a'] == 1e15) return -1;
                res += arr[s[i] - 'a'][t[i] - 'a'];                
            }
        }
        return res == 1e15 ? -1 : res;
    }
};
