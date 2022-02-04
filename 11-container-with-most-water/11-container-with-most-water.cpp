class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans=INT_MIN;
        int s=0,e=n-1;
        while(s<e)
        {
            ans=max(ans,min(h[s],h[e])*(e-s));
            if(h[s]<h[e])
                s++;
            else
                e--;
        }
        return ans;
    }
};