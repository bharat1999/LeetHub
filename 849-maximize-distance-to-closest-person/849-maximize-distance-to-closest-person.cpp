class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int m1 = INT_MIN;
        int n = s.size();
        vector<int> ones;
        for(int i=0;i<n;i++)
        {
            if(s[i]==1)
                ones.push_back(i);
        }
        int idx=ones[0];
        for(auto x:ones)
        {
            m1=max(x-idx,m1);
            idx=x;
        }
        m1--;
        int m2,m3;
        m2=ones[0];
        m3=n-1-ones[ones.size()-1];
        m1=m1%2?m1/2+1:m1/2;
        return max(m1,max(m2,m3));
    }    
};