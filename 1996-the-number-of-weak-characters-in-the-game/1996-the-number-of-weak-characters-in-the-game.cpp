class Solution {
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int ans = 0;
        int n = p.size();
        int max_defence = p[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
             // if curr_defence is less than max_defence
            if(p[i][1] < max_defence)
                ans++;
            max_defence = max(max_defence, p[i][1]);
        }
        return ans;
    }
};