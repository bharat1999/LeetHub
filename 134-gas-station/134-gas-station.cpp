class Solution {
    bool check(vector<int>& gas, vector<int>& cost,int idx)
    {
        int n=cost.size();
        int count=n;
        int g=0;
        while(count--)
        {
            g+=gas[idx]-cost[idx];
            idx++;
            idx=idx%n;
            if(g<0)
                return false;
        }
        return true;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        float ratio;
        int max=INT_MIN,idx;
        vector<int> possible;
        for(int i=0;i<n;i++)
        {
            ratio= float(gas[i])/cost[i];
            if(ratio>=1)
            {
                possible.push_back(i);
            }
        }
        for(auto x:possible)
        {
            if(check(gas,cost,x))
                return x;
        }
        return -1;
    }
};