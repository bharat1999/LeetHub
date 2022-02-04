class Solution {
public:
    
    int change(vector<int> coins,int amount,int size)
    {
        if(size==0)
            return 1;  
        int dp[size][amount+1];
        for(int i=0;i<size;i++)
            dp[i][0]=1;
        for(int i=0;i<size;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int x = i-1>=0 ? dp[i-1][j]:0; // ek baar coin nhi lia
                int y = j-coins[i]>=0?dp[i][j-coins[i]]:0; // ek baar le lia
                dp[i][j]=x+y;   
            }
        }   
        return dp[size-1][amount]; // ek baad last wala lege ek baar nahi
}

    
    int change(int amount, vector<int>& coins) {
        return change(coins,amount,coins.size());
    }
};