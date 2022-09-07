class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int n = s.size();
        int i = 0;
        int order = 1;
        bool decimal = false;
        while(s[i]==' ')
            i++;
        bool sign = true;
        if(s[i]=='-' or s[i]=='+')
        {
            if(s[i]=='-')
                sign = false;
            i++;
        }
        for(int j=i;j<n;j++)
        {
            char x = s[j];
            if(x=='-' or x=='+')
            {
                if(sign)
                    return res;
                return -1*res;
            }
            else if(x=='.')
                decimal = true;
            else if(!isdigit(x))
            {
                if(!sign)
                    return -1*res;
                return res;
            }
            else if(isdigit(x))
            {
                if(!decimal)
                    res*=10;
                res+= ((x-'0')*order);
            }
            if(res>INT_MAX)
            {
                if(!sign)
                    return INT_MIN;
                return INT_MAX;
            }
            if(decimal)
                order/=10;
        }
        if(!sign)
            return res*-1;
        return res;
    }
};