class Solution {
public:
    static constexpr int mod = 1000000007;
    int colorTheGrid(int m, int n) {
        int mask_end = pow(3, m), res = 0;
        unordered_map<int, vector<int>> valid, adjacent;
        for (int mask = 0; mask < mask_end; ++mask) {
            vector<int> color;
            int mm = mask;
            bool check = true;
            for (int i = 0; i < m; ++i) color.push_back(mm % 3), mm /= 3;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) valid[mask] = move(color);
        }
        for (const auto& [mask1, color1] : valid) {
            for (const auto& [mask2, color2] : valid) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (color1[i] == color2[i]) {
                        check = false;
                        break;
                    }
                }
                if (check) adjacent[mask1].push_back(mask2);
            }
        }
        vector<int> f(mask_end);
        for (const auto& [mask, _] : valid) f[mask] = 1;
        for (int i = 1; i < n; ++i) {
            vector<int> g(mask_end);
            for (const auto& [mask2, _] : valid) {
                for (int mask1 : adjacent[mask2]) {
                    g[mask2] += f[mask1];
                    if (g[mask2] >= mod) g[mask2] -= mod;
                }
            }
            f = move(g);
        }
        for (int num : f) {
            res += num;
            if (res >= mod) res -= mod;
        }
        return res;
    }
};
