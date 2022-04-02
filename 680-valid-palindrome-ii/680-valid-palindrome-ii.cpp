class Solution {
    bool check(string &a,int i,int j)
    {
        int s = i;
        int e = j;
        while(s<e)
        {
            if(a[s]!=a[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
public:
    bool validPalindrome(string a) {
        int s = 0;
        int e = a.size()-1;
        while(s<e)
        {
            // check by removing either left or right char
            if(a[s]!=a[e])
                return check(a,s+1,e) or check(a,s,e-1);
            s++;
            e--;
        }
        return true;
    }
};