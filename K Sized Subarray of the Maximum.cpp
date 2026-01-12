class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int n = points.size(), res = 0;
        for (int i = 1; i < n; i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            res += max(dx, dy);
        }
        return res;
    }
};
