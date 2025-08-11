#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(string s) {
        int n = s.length();
        if (n < 2) return 0;

        vector<int> d = manacherOdd(s);
        vector<int> maxEnd(n), maxStart(n);

        priority_queue<pair<int,int>> pq;
        int centerIdx = 0;
        for (int e = 0; e < n; e++) {
            while (centerIdx < n && centerIdx <= e) {
                int c = centerIdx;
                int B = 1 - 2 * c;
                int R = c + d[c] - 1;
                pq.push({B, R});
                centerIdx++;
            }
            while (!pq.empty() && pq.top().second < e) pq.pop();
            if (!pq.empty()) {
                maxEnd[e] = 2 * e + pq.top().first;
            } else {
                maxEnd[e] = 1;
            }
        }

        vector<int> maxPref(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (maxEnd[i] > cur) cur = maxEnd[i];
            maxPref[i] = cur;
        }

        priority_queue<pair<int,int>> pq2;
        int centerIdx2 = n - 1;
        for (int sIdx = n - 1; sIdx >= 0; sIdx--) {
            while (centerIdx2 >= 0 && centerIdx2 >= sIdx) {
                int c = centerIdx2;
                int C = 2 * c + 1;
                int L = c - d[c] + 1;
                pq2.push({C, L});
                centerIdx2--;
            }
            while (!pq2.empty() && pq2.top().second > sIdx) pq2.pop();
            if (!pq2.empty()) {
                maxStart[sIdx] = -2 * sIdx + pq2.top().first;
            } else {
                maxStart[sIdx] = 1;
            }
        }

        vector<int> maxSuff(n);
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (maxStart[i] > cur) cur = maxStart[i];
            maxSuff[i] = cur;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, maxPref[i] + maxSuff[i + 1]);
        }
        return ans;
    }

    vector<int> manacherOdd(string s) {
        int n = s.length();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = 1;
            if (i <= r) k = min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return d;
    }
};

//GFG POTD solution for 11 August
