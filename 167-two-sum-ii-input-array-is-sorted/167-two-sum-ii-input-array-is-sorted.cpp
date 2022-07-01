class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int s = 0;
        int e= n.size()-1;
        while(s<e)
        {
            if(n[s]+n[e]==target)
                return {s+1,e+1};
            else if(n[s]+n[e]<target)
                s++;
            else
                e--;
        }
        return {};
    }
};