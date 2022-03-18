class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26);
        // to keep track of which charcter we have in our ans
        vector<bool> visited(26,false);
        // using string as it also insert and delete form end in constant time
        string ans="";
        for(auto x:s)
            freq[x-'a']++;
        for(auto x:s)
        {
            freq[x-'a']--;
            if(!visited[x- 'a'])
            {
                // Last character > s[i]
                // and its count > 0
                while(ans.size() > 0 and ans.back() > x and freq[ans.back() - 'a'] > 0)
                {
                    // marking letter as unvisited to use again
                    visited[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                
                // Add x in ans and
                // mark it visited
                ans+= x;
                visited[x - 'a'] = 1;
            }
        }
        return ans;
    }
};