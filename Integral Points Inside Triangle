class Solution {
public:
    long long int gcd(long long int a, long long int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long int boundaryPoints(long long int x1, long long int y1, long long int x2, long long int y2) {
        return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
    }

    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
         long long int area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) / 2;
        
         long long int B = boundaryPoints(p[0], p[1], q[0], q[1]) +
                          boundaryPoints(q[0], q[1], r[0], r[1]) +
                          boundaryPoints(r[0], r[1], p[0], p[1]) - 3;

         long long int I = area - B / 2 + 1;

        return I;
    }
};
