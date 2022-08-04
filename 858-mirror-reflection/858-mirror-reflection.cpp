class Solution {
public:
    int mirrorReflection(int p, int q) {
        while((p%2==0) && (q%2==0)){
            p/=2;
            q/=2;
        }
        // p is even and q odd so answer is 2
        if(p%2==0 and q%2)
            return 2;
        // both odd so answer is 1
        if(p%2 and q%2)
            return 1;
        return 0;
    }
};