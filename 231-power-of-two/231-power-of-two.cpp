class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        //If a number is a power or two is will ony have the first bit set
        // So we AND it with n-1
        return ((n&(n-1))==0);
    }
};