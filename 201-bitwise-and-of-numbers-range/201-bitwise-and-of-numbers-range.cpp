class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right==0 or left==0)
            return 0;
        if(left == right)
            return left;
        if(right-left==1)
            return right&left;
        int leftmsb=log2(left);
        int rightmsb=log2(right);
        if(leftmsb<rightmsb)
            return 0;
        int ans=0;
        cout<<leftmsb;
        for(int i=leftmsb;i>=0;i--)
        {
            if(((1<<i)&left)!=((1<<i)&right))
                break;
            if(((1<<i)&left)!=0)
            ans+=1<<i;
        }
        return ans;
    }
};