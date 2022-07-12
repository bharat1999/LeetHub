class Solution {
    bool solve(vector<int> &m,int i,int s1,int s2,int s3,int s4,int side)
    {
        if(i==m.size())
        {
            if(s1==s2 and s2==s3 and s3==s4 and s4==s1)
                return true;
            else
                return false;
        }
        if(s1+m[i]<=side and solve(m,i+1,s1+m[i],s2,s3,s4,side))
           return true;
        if(s2+m[i]<=side and solve(m,i+1,s1,s2+m[i],s3,s4,side))
           return true;
        if(s3+m[i]<=side and solve(m,i+1,s1,s2,s3+m[i],s4,side))
           return true;
        if(s4+m[i]<=side and solve(m,i+1,s1,s2,s3,s4+m[i],side))
            return true;
        return false;
    }

public:
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(),m.end(),0);
        if(sum%4)
            return false;
        sort(m.begin(),m.end(),greater<int>());
        if(m[0]>sum/4)
            return false;
        return solve(m,0,0,0,0,0,sum/4);
    }
};