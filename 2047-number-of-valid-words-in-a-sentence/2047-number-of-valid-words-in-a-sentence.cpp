class Solution {
     bool valid(string &s) {
        int  N = s.size();
        int hyphen=0;
        for (int i = 0; i < N; ++i) 
        {
            if (isdigit(s[i])) return false;
            if (isalpha(s[i])) continue;
            if (s[i] == '-') 
            {
                if(++hyphen>1)
                    return false;
                if (i==0 or i==N-1 or !isalpha(s[i-1]) or !isalpha(s[i+1]))
                    return false;
            } 
            else if (i != N - 1) 
                return false; 
        }
        return true;
    }
public:
    int countValidWords(string s) {
        string w;
        istringstream ss(s);
        int ans = 0;
        while (ss >> w) 
            ans += valid(w);
        return ans;
    }
};