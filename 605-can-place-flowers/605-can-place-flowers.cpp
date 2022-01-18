class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int i=0;
        int s=f.size();
        if(n==0)
            return true;
        if(s==1)
            return f[0]==0?true:false;
        while(i<s)
        {
            if(f[i]==0 and (i==0 or f[i-1]==0) && (i==s-1 or f[i+1]==0))
            {
                f[i++]=1;
                n--;
            }
            i++;
            if(n==0)
                return true;
        }
        return false;
    }
};