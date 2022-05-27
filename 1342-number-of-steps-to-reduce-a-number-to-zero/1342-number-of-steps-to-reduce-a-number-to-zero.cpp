class Solution {
public:
    int numberOfSteps(int n) {
        if(n==0)
            return 0;
        int op1,op2;
        op1=op2=INT_MAX;
        if(n%2==0)
            op1 = 1 + numberOfSteps(n/2);
        else
            op2 = 1 + numberOfSteps(n-1);
        return min(op1,op2);
    }
};