class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest= INT_MAX;
        for(auto x:nums)
        {
            if(abs(x)<abs(closest))
                closest = x;
            if(abs(x)==abs(closest))
                closest=max(x,closest);
        }
        return closest;
    }
};