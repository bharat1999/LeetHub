class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char,int> freq;
        for(auto x:words2)
        {
            unordered_map<char,int> tmp;
            for(auto c:x)
                tmp[c]++;
            for(auto y:tmp)
                freq[y.first] = max(freq[y.first],y.second);
        }
        for(auto x:words1)
        {
            unordered_map<char,int> tmp2;
            for(auto c:x)
                tmp2[c]++;
            bool f = true;
            for(auto y:freq)
            {
                if(tmp2[y.first]<y.second)
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