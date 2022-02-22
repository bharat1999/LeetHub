class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
          int i = INT_MAX, j = INT_MAX;
        for (auto x : nums) {
            if (x < i)
                i = x;
            else if(i < x and x < j)
                j = x;
            else if (j < x)
                return true;
        }
        return false;
    }
};