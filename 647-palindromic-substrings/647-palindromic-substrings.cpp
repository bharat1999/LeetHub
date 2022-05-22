class Solution {
    int n;
    int count(int l,int r,string s)
    {
        int c = 0;
        while(l>=0 and r<n and s[l]==s[r])
        {
            c++;
            l--;
            r++;
        }
        return c;
    }
public:
    int countSubstrings(string s) {
        int ans=0;
        n = s.size();
        for(int i=0;i<n;i++)
            ans+=count(i,i,s)+count(i,i+1,s);
        return ans;
        
    }
};