class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        unordered_map<char,string> ptos;
        unordered_map<string,char> stop;
        vector<string> words;
        string tmp="";
        for(auto x:s)
        {
            if(x==' ')
            {
                words.push_back(tmp);
                tmp="";
            }
            else
                tmp.push_back(x);
        }
        words.push_back(tmp);
        int m=words.size();
        if(m!=n)
            return false;
        for(int i=0;i<n;i++)
        {
            if(ptos.find(pattern[i])!=ptos.end() or stop.find(words[i])!=stop.end())
            {
                if(ptos[pattern[i]]!=words[i] or stop[words[i]]!=pattern[i])
                    return false;
            }
            else
            {
                ptos[pattern[i]]=words[i];
                stop[words[i]]=pattern[i];
            }    
        }
        return true;
    }
};