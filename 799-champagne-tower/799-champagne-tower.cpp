class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> qty_dp(101,vector<double> (101));
        // initially top glass have poured amount of champagne
        qty_dp[0][0] = poured;
        for (int i = 0; i < 100; i++) 
        {
            for (int j = 0; j <= i; j++) 
            {
                // if current glass have more than 1L than it will equally
                // pour in its left and right below glass
                // that is equalt to i+1,j and i+1,j+1
                if (qty_dp[i][j] > 1) 
                {
                    qty_dp[i + 1][j] += (qty_dp[i][j] - 1) / 2.0;
                    qty_dp[i + 1][j + 1] += (qty_dp[i][j] - 1) / 2.0;
                    // after pouring it will left with 1L
                    qty_dp[i][j] = 1;
                }
            }
        }
        return qty_dp[query_row][query_glass];

    }
};