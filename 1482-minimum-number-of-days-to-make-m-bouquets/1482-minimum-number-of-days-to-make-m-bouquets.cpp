class Solution {
    bool check(vector<int>&b ,int mid , int m,int k)
    {
        int f = 0;
        int bouquets = 0;
        for(int i=0,n=b.size();i<n;i++)
        {
            // we can't take current flower so make f = 0
            // as we need atmax mid days
            if(b[i]>mid)
                f=0;
            // bouqueut possible
            else
            {
                f++;
                if(f==k)
                {
                    bouquets++;
                    f=0;
                }   
            }
        }
        return bouquets>=m;
    }
public:
    int minDays(vector<int>& b, int m, int k) {
        int s = 1;
        int e = *max_element(b.begin(),b.end());
        int ans=e;
        if(m*k>b.size())
            return -1;
        while(s<=e)
        {
            int mid = e -(e-s)/2;
            if(check(b,mid,m,k))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};