class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2)
            return{};
        vector<long long>ans;
        long long i=2;
        long long curSum=0;
        while(curSum+i<=finalSum)
        {
            ans.push_back(i);
            curSum+=i;
            i+=2;
        }
        // if curSum <Final sum we will add the required num
        // that is finalSum- curSum to the last element of ans vector
        ans[ans.size()-1]+=finalSum-curSum;
        return ans;
    }
};