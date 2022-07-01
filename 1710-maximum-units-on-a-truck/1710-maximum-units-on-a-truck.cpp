class Solution {
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]>b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        sort(b.begin(),b.end(),cmp);
        int ans = 0;
        for(auto x:b)
        {
            if(truckSize)
            {
                int mx= min(truckSize,x[0]);
                ans+=mx*x[1];
                truckSize-=mx;
            }
            else
                break;
        }
        return ans;
    }
};