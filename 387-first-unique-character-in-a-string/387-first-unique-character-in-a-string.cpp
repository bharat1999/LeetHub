class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};