class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs[0].size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            char c = strs[0][i];
            for(auto x:strs)
            {
                if(x[i]!=c)
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};