class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++)
            tank += gas[i] - cost[i];
        if(tank < 0) 
            return - 1;
        // at this point out answer is guaranteed
        int start = 0;
        tank = 0;
        for(int i = 0; i < n; i++)
        {
            int curGain = gas[i] - cost[i];
            if(tank + curGain < 0)
            {
                start = i + 1;
                tank = 0;
            }
            else
                tank+= curGain;
        }
        return start;
    }
};