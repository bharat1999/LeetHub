class Solution {
    vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(string& d,int i,int n,string& tmp)
    {
        if(i==n)
        {
            ans.push_back(tmp);
            return;
        }
        string key = map[d[i]-'0'];
        for(int j=0;j<key.size();j++)
        {
            tmp.push_back(key[j]);
            solve(d,i+1,n,tmp);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)
            return ans;
        string tmp;
        solve(digits,0,n,tmp);
        return ans;
    }
};