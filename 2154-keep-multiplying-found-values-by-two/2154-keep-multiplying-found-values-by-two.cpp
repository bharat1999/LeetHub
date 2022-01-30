class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s(nums.begin(),nums.end());
        while(true)
        {
            if(s.count(original)) 
                original*=2;
            else
                break;
        }
        return original;
    }
};