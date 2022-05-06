class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                if(st.top().second==k)
                {
                    for(int i=1;i<=k;i++)
                        st.pop();
                }
                if(!st.empty() and st.top().first==s[i])
                    st.push({s[i],st.top().second+1});
                else
                    st.push({s[i],1});
                
            }
            i++;
        }
        if(st.top().second==k)
        {
            for(int i=1;i<=k;i++)
                st.pop();
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};