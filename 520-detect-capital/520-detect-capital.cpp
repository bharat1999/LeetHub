class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        for(auto x:word)
        {
            if(isupper(x))
                c++;
        }
        int n = word.size();
        if(c==n or c==0)
            return true;
        if(c>1 and c<n)
            return false;
        if(isupper(word[0]))
            return true;
        return false;
    }
};