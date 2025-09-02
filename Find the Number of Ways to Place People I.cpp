class Solution {
public:
    struct Pointer {
        int x, y;
    };
    bool isBottomRightOf(const Pointer& tl, const Pointer& br) {
        return tl.x <= br.x && tl.y >= br.y;
    }
    bool isPointerInsideRectangle(const Pointer& pointer, const Pointer& tl, const Pointer& br) {
        int x = pointer.x, y = pointer.y;
        int x1 = tl.x, y1 = tl.y, x2 = br.x, y2 = br.y;
        return (isBottomRightOf(tl, br) && x1 <= x && x <= x2 && y1 >= y && y >= y2);
    }
    int numberOfPairs(vector<vector<int>>& rectangles) {
        vector<Pointer> pointers;
        for (auto rect : rectangles) pointers.push_back({rect[0], rect[1]});
        int n = pointers.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isBottomRightOf(pointers[i], pointers[j])) {
                    bool isValid = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        if (isPointerInsideRectangle(pointers[k], pointers[i], pointers[j])) {
                            isValid = false;
                            break;
                        }
                    }
                    if (isValid) res++;
                }
            }
        }
        return res;
    }
};
