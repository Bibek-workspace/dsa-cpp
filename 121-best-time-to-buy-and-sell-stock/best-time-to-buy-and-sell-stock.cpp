class Solution {
public:
    int maxProfit(vector<int>& price) {
        int mini = price[0];
        int max_profit = 0;
        int n = price.size();
        for (int i= 1; i < n ; i++ ){
            int cost = price[i] - mini;
            max_profit = max(max_profit, cost);
            mini = min(mini, price[i]);
        }
        return max_profit;
    }
};