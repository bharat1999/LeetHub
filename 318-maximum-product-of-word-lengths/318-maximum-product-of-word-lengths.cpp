class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto x:words[i])
                mask[i]|=1<<(x-'a');
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((mask[i]&mask[j])==0)
                    ans = max(ans,int(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};