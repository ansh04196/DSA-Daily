class Solution {
public:
    double area(vector<int> &a, vector<int> &b, vector<int> &c){
        long long x1 = b[0] - a[0], y1 = b[1] - a[1];
        long long x2 = c[0] - a[0], y2 = c[1] - a[1];
        long long cross = x1 * y2 - x2 * y1; 
        return fabs(cross) * 0.5;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    ans = max(ans, area(points[i], points[j], points[k]));
        return ans;
    }
};
