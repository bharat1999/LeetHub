class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        double i = double(log10(n))/log10(3);
        if(i - int(i)==0)
            return true;
        return false;
    }
};