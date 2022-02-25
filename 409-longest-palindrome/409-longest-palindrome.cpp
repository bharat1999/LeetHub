class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        unordered_map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        for(auto x:mp)
            if((x.second)%2)
                odd++;
        int len = s.size();
        // odd is the number of unique char having odd frequency
        // by subtracting odd we are removing one instance of each of that
        // char so its freq become even , now we can take 1 odd ,so if no of odds
        // is more than 0 we add 1 to ans
        return len - odd + (odd>0);
    }
};