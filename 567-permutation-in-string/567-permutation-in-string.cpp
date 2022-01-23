class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
            return false;
        vector<int> freq1(26),freq2(26);
        for(auto x:s1)
            freq1[x-'a']++;
        for(int i=0;i<s1.size();i++) // checking first window of s2;
            freq2[s2[i]-'a']++;
        if(freq1==freq2) // if both equal means permutation possible
            return true;
        // check remaining windows of s2;
        for(int i = s1.size();i<s2.size();i++)
        {
            freq2[s2[i]-'a']++;
            // remove first char of last window
            freq2[s2[i-s1.size()]-'a']--;
            // check if new window is a permutation or not
            if(freq1==freq2)
                return true;
        }
        // if any window is not a permutation return false;
        return false;
    }
};