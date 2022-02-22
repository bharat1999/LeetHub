class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n)
        {
            n--;
            char c = (n%26) + 'A';
            n/=26;
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};