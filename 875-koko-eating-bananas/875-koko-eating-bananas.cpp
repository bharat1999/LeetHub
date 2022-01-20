class Solution {
    bool check(vector<int>&piles,int mid,int h)
    {
        int hours=0;
        for(auto p:piles)
            hours+=p/mid+(p%mid!=0);
        return hours<=h;
    }
    int solve(vector<int> &p,int h)
    {
        int s=1,e=p[p.size()-1];
        while(s<e)
        {
            int mid=(e+s)/2;
            if(check(p,mid,h))
            {
                e=mid;
            }
            else
                s=mid+1;
        }
        return e;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        return solve(piles,h);
    }
};