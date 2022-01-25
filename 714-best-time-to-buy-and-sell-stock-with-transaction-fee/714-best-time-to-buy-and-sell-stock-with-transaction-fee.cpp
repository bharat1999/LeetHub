class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0,hold = -prices[0];
        for(auto p:prices)
        {
            cash = max(cash,hold + p - fee);
            hold = max(hold,cash-p);
        }
        return cash;
    }
};