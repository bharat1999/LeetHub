class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=1;i<=n;i++)
        {
            if(k-26>=n-i)
            {
                ans.push_back('z');
                k-=26;
            }
            else
            {
                // largest character possible after which we can add remaining chars
                int largest = k-(n-i);
                k-=largest;
                ans.push_back(largest-1+'a');
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};