class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=INT_MIN;
        for(auto x:accounts)
        {
            int tmp=0;
            for(auto y:x)
                tmp+=y;
            sum=max(sum,tmp);
        }    
        return sum;
    }
};