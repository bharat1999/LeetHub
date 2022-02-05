class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) 
        {
            // if both char match we increase s string pointer to find next char
            if(s[i] == t[j]) 
                i++;
            j++;
        }
        // if we found all the chars of s than its true else false;
        return i == m ? 1 : 0;
    }
};