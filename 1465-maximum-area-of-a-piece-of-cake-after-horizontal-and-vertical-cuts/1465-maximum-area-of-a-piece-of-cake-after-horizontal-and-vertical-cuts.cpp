class Solution {
    int mod = 1e9 + 7;
public:
    int maxArea(int H, int W, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long mx = h[0],my = v[0];
        for(int i=0;i<h.size()-1;i++)
            mx=max(mx,(long long)h[i+1]-h[i]);
        for(int i=0;i<v.size()-1;i++)
            my=max(my,(long long)v[i+1]-v[i]);
        mx = max(mx,(long long)H-h[h.size()-1]);
        my = max(my,(long long)W-v[v.size()-1]);

        long long ans = ((mx%mod)*(my%mod))%mod;
        return int(ans);
    }
};