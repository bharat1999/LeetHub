class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x:nums)
            st.insert(x);
        int ans = 0;
        int tmp = 1;
        for(auto x:nums)
        {
            if(st.find(x-1)==st.end())
            {
                int y = x;
                tmp=1;
                while(st.find(y+1)!=st.end())
                {
                    y++;
                    tmp++;
                }
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};