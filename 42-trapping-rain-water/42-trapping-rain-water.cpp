class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> left(n),right(n);
        left[0]=h[0];
        for(int i=1;i<n-1;i++)
            left[i]=max(left[i-1],h[i]);
        right[n-1]=h[n-1]; 
        for(int i=n-2;i>0;i--)
            right[i]=max(right[i+1],h[i]);
        for(auto x:left)
            cout<<x<<" ";
        cout<<endl;
        for(auto x:right)
            cout<<x<<" ";
        int res=0;
        for(int i=1;i<n-1;i++)
            res+=min(left[i],right[i])-h[i];
        return res;
    }
};