class Solution {
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_set<int> st1,st2;
        unordered_map<int,int> mp;
        for(auto x:numsDivide)
            st1.insert(x);
        numsDivide.clear();
        for(auto x:st1)
            numsDivide.push_back(x);
        for(auto x:nums)
        {
            st2.insert(x);
            mp[x]++;
        }
        nums.clear();
        for(auto x:st2)
            nums.push_back(x);
        sort(nums.begin(),nums.end());
        int del = 0;
        for(auto x:nums)
        {
            bool found = true;
            for(auto y:numsDivide)
            {
                if(gcd(x,y)!=x)
                {
                    del+=mp[x];
                    found=false;
                    break;
                }
            }
            if(found)
                return del;
        }
        return -1;
    }
};