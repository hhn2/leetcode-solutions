// Last updated: 9/27/2025, 7:37:22 PM
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int result = 2;

        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> slopeCount;
            int localMax = 0;

            for (int j = i+1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                slopeCount[{dy, dx}]++;
                localMax = max(localMax, slopeCount[{dy, dx}]);
            }

            result = max(result, localMax + 1); // +1 for the base point itself
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};
