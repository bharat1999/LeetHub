class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f1(26,0),f2(26,0);
        for(auto x:t)
            f1[x-'a']++;
        for(auto x:s)
                f2[x-'a']++;
        int sum = 0;
        for(int i=0;i<26;i++)
            sum+=abs(f1[i]-f2[i]);
        return sum/2;
    }
};