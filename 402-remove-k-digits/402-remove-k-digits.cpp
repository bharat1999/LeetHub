class Solution {
public:
    string removeKdigits(string num, int k) {
        // implementation is like stack but using string to avoid
        // conversion in and also stack and string have push and pop
        // at end
        string ans="";
        for(char &c:num)
        {
            // whenever we encounter a char less than top
            // we remove top bcz that current small char
            // can lead to smaller number
            while(ans.size() && ans.back()>c && k)
            {
                ans.pop_back();
                k--;
            }
            // if ans is not empty push otherwise if its empty
            // c should not be zero to avoid leading zeroes
            if(ans.size()||c!='0')
                ans.push_back(c);
        }
        // if after iterating the whole string k is left
        while(ans.size() && k--)
            ans.pop_back();
        return (ans=="")?"0":ans;
    }
};