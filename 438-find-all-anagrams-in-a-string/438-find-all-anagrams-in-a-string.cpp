class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int window_len = p.size();
        int len = s.size();
        vector<int> s_arr(26),p_arr(26);
        if(window_len>len)
            return ans;
        for(int i=0;i<window_len;i++)
            p_arr[p[i]-'a']++;
        //first window
        for(int i=0;i<window_len;i++)
            s_arr[s[i]-'a']++;
        if(s_arr==p_arr)
            ans.push_back(0);
        for(int i=1;i<=len-window_len;i++)
        {
            s_arr[s[i-1]-'a']--;
            s_arr[s[i+window_len-1]-'a']++;
            if(s_arr==p_arr)
                ans.push_back(i);
        }
        return ans;
    }
};