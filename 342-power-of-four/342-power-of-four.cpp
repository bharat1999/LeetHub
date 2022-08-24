class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double p = double(log10(n))/log10(4);
        if(p - int(p)==0)
            return true;
        return false;
    }
};