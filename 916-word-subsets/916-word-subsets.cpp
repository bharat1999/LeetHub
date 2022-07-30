class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq(26);
        for(auto x:words2)
        {
            vector<int> tmp(26);
            for(auto c:x)
                tmp[c-'a']++;
            for(int i=0;i<26;i++)
                freq[i] = max(freq[i],tmp[i]);
        }
        for(auto x:words1)
        {
            vector<int> tmp2(26);
            for(auto c:x)
                tmp2[c-'a']++;
            bool f = true;
            for(int i=0;i<26;i++)
            {
                if(tmp2[i]<freq[i])
                {
                    f = false;
                    break;
                }
            }
            if(f)
                ans.push_back(x);
        }
        return ans;
    }
};