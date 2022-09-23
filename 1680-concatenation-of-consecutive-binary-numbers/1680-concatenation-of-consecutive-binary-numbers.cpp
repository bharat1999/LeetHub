class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0; 
        int mod = 1e9 + 7;
        
        for(int i=1;i<=n;i++)
        {
            // no of bits in binary of i
            int len = log2(i) + 1;
            // left shift the ans and then add the i number in it,(concatenate)
            ans = ((ans << len) % mod + i) % mod; 
        }
        return ans % mod;
    }
};