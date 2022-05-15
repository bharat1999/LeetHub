class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,string> mp;
        for(auto x:words)
        {
            string t = x;
            sort(t.begin(),t.end());
            mp[x] = t;
        }
        int n = words.size();
        int s=0,e=0;
        vector<string> ans;
        while(s<n)
        {
            while(e<n and mp[words[s]]==mp[words[e]])
                e++;
            ans.push_back(words[s]);
            s=e;
        }
        return ans;
    }
};