class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
            return -1;
        if(needle=="")
            return 0;
        vector<int> freq1(26),freq2(26);
        for(auto x:needle)
            freq1[x-'a']++;
        int n = needle.size();
        //first window
        for(int i=0;i<n;i++)
            freq2[haystack[i]-'a']++;
        if(freq1==freq2 and haystack.substr(0,n)==needle)
            return 0;
        // all other windows
        for(int i=n,s=haystack.size();i<s;i++)
        {
            freq2[haystack[i-n]-'a']--;
            freq2[haystack[i]-'a']++;
            if(freq1==freq2 and haystack.substr(i-n+1,n)==needle)
            {
                return i-n+1;
            }
        }
        return -1;
    }
};