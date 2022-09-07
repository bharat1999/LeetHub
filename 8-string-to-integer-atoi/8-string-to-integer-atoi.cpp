class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = -1;
        int n = s.size();
        int i = 0;
        int order = 1;
        bool decimal = false;
        while(s[i]==' ')
            i++;
        for(int j=i;j<n;j++)
        {
            char x = s[j];
            if(x=='-')
            {
                if(sign!=-1 or i!=j)
                    break;
                sign = 0;
            }
            else if(x=='+')
            {
                if(sign!=-1 or i!=j)
                    break;
                sign=1;
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