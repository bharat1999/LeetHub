class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romToInt = {{'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500},{'M', 1000}};
        int i, ln = s.size(), ans = 0,last = 0;
        for(i=ln-1; i>=0; i--) 
        {
            // if current is less than value of prev
            // subtract current
            if(romToInt[s[i]] < last)
                ans -= romToInt[s[i]];
            else
                ans += romToInt[s[i]];
            last = romToInt[s[i]];
        }
        return ans;
    }
};