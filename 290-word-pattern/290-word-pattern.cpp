class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        // pattern char to string map
        unordered_map<char,string> ptos;
        // strung to pattern car map;
        unordered_map<string,char> stop;
        // to store words as seperate strings
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
        // if no of words not equal to pattern length its false
        if(m!=n)
            return false;
        for(int i=0;i<n;i++)
        {
            // if we have a char already attached to a string or
            // a string already attched to a pattern
            if(ptos.find(pattern[i])!=ptos.end() or stop.find(words[i])!=stop.end())
            {
                // check if currrent char is same as prev matched with same string or
                // current string is same as prev matched with same char
                if(ptos[pattern[i]]!=words[i] or stop[words[i]]!=pattern[i])
                    return false;
            }
            // if not present add to map
            else
            {
                ptos[pattern[i]]=words[i];
                stop[words[i]]=pattern[i];
            }    
        }
        return true;
    }
};