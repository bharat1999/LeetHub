class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i=0,n=s.size();i<=n-k;i++)
        {
            string t = s.substr(i,k);
            st.insert(t);
        }
        return st.size()==(1<<k);
        
    }
};