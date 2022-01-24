class Solution {
public:
    int maxProfit(vector<int>& p) {
        int profit = 0;
        int cur_min = p[0];
        for(auto x:p)
        {
            if(x>cur_min)
                profit = max(profit,x-cur_min);
            else
                cur_min = x;
        }
        return profit;
    }
};