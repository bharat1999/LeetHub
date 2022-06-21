class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_to_t,t_to_s;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            // no mapping so add
            if(s_to_t.count(s[i])==0 and t_to_s.count(t[i])==0)
            {
                s_to_t[s[i]] = t[i];
                t_to_s[t[i]] = s[i];
            }
            else if(s_to_t[s[i]]!=t[i] and t_to_s[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};