class Solution {
 
    bool check(string s, string p)
    {
        int j = 0; 
        for (int i = 0; i < s.size() and j < p.size(); i++)
        {    
            if (p[j] == s[i])
                j++;
        }
        return (j == p.size());
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable)
    {
        int k = removable.size(), ans=-1;
        int lo = 0, hi = k-1;
        while(lo<=hi)
        {    
            int mid = (lo+hi)/2;
            string t = s;
            for(int i=0; i<=mid; i++)
                t[removable[i]] = '#';
            if(check(t, p))
            {
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return ans+1;
    }
};