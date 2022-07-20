class Solution {
public:
   
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = words.size();
        unordered_map<char, vector<int>> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]].push_back(i);
        for(auto x: words)
        {
            int last = -1;
		    for(char c:x)
            {
                auto& v = mp[c];
                auto it = upper_bound(v.begin(),v.end(),last);
                if(it==v.end())
                {
                    count--;
                    break;
                }
                last = *it;
            }
        }
        return count;
    }
};