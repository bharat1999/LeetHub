class Solution {
    int nextSum(int n)
    {
        int sum = 0 ;
        while(n)
        {
            int tmp = n%10;
            sum+=tmp*tmp;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n!=1 and !visited.count(n))
        {
            visited.insert(n);
            n = nextSum(n);
        }
        return n==1;
    }
};