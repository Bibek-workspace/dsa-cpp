class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                double x1 = darts[i][0];
                double y1 = darts[i][1];
                double x2 = darts[j][0];
                double y2 = darts[j][1];

                double dx = x2 - x1;
                double dy = y2 - y1;
                double d = sqrt(dx * dx + dy * dy);

                if (d > 2.0 * r)
                    continue;

                double midX = (x1 + x2) / 2.0;
                double midY = (y1 + y2) / 2.0;

                double h = sqrt(r * r - (d * d) / 4.0);

                double perpX = -dy / d;
                double perpY = dx / d;

                double cx1 = midX + h * perpX;
                double cy1 = midY + h * perpY;

                double cx2 = midX - h * perpX;
                double cy2 = midY - h * perpY;

                int count1 = 0;
                int count2 = 0;

                for (int k = 0; k < n; k++) {
                    double dist1 = sqrt(
                        (darts[k][0] - cx1) * (darts[k][0] - cx1) +
                        (darts[k][1] - cy1) * (darts[k][1] - cy1)
                    );

                    double dist2 = sqrt(
                        (darts[k][0] - cx2) * (darts[k][0] - cx2) +
                        (darts[k][1] - cy2) * (darts[k][1] - cy2)
                    );

                    if (dist1 <= r + 1e-7)
                        count1++;

                    if (dist2 <= r + 1e-7)
                        count2++;
                }

                ans = max(ans, max(count1, count2));
            }
        }

        return ans;
    }
};