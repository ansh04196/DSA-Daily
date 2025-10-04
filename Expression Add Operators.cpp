class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, area = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            area = max(area, (r - l) * h);
            if (height[l] <= h) l++;
            if (height[r] <= h) r--;
        }
        return area;
    }
};
