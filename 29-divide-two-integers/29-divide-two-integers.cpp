class Solution {
public:
    int divide(int dividend, int divisor) {
        //Handling corner cases
        if(dividend==INT_MIN and divisor==-1)
            return INT_MAX;
        if(dividend==INT_MIN and divisor==1) 
            return INT_MIN;

        long int dd = abs(dividend), dv = abs(divisor);
        
        int res=0;
        while(dv<=dd) 
        {
            long int mul=dv, tmp=1;
            while(mul<=dd-mul) 
            {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            dd-=mul;
        }
        
        if((dividend<0 and divisor>0) or (dividend>0 and divisor<0)) 
            return -res;
        return res;
    }
};