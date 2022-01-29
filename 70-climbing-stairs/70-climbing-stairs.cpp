class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==2)
            return n;
        int f=1;
        int s=2;
        int ans;
        for(int i=3;i<=n;i++)
        {
            ans = f + s;
            f = s;
            s = ans;
        }
        return ans;
    }
};