class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++)
        {
            if(rating[i]>rating[i-1])
                ans[i] = ans[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(rating[i]>rating[i+1])
                ans[i] = max(ans[i],ans[i+1]+1);
        }
        int sum = accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};