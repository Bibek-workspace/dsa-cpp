class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -1);

        dp[0] = 0;

        for (int t = 1; t <= target; t++) {
            for (int i = 0; i < 9; i++) {
                if (t >= cost[i] && dp[t - cost[i]] != -1) {
                    dp[t] = max(dp[t], dp[t - cost[i]] + 1);
                }
            }
        }

        if (dp[target] == -1)
            return "0";

        string ans = "";

        for (int digit = 9; digit >= 1; digit--) {
            while (target >= cost[digit - 1] &&
                   dp[target] == dp[target - cost[digit - 1]] + 1) {
                ans += char('0' + digit);
                target -= cost[digit - 1];
            }
        }

        return ans;
    }
};