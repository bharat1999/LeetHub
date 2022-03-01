class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0 , it will store no of set bits
            int sum = 0;
            int num = i;
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                // it will add 1 if remainder is not 0
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
        return ans;
    }
};