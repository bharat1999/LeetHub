class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> dig;
        while(n)
        {
            int r= n%10;
            dig[r]++;
            n/=10;
        }
        // creating all power of 2
        for(int i=0;i<32;i++)
        {
            int x = 1<<i;
            unordered_map<int,int> digPow;
            while(x)
            {
                int xR = x%10;
                digPow[xR]++;
                x/=10;
            }
            bool flag = true;
            // checking if this power digits equal to digits of n
            for(auto x:digPow)
            {
                if(x.second!=dig[x.first])
                {
                    flag = false;
                    break;
                }   
            }
            for(auto x:dig)
            {
                if(x.second!=digPow[x.first])
                {
                    flag = false;
                    break;
                }   
            }
            // if flag is true digits are same
            if(flag)
                return true;
        }
        // Reach here mean no power of 2 have same digits as of n
        return false;
    }
};