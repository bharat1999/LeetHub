class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> tmp;
        int c=1;
        for(int i=n-1;i>=0;i--)
        {
            if(c==1)
            {
                if(digits[i]+1<=9)
                {
                    tmp.push_back(digits[i]+1);
                    c=0;
                }
                else
                {
                    tmp.push_back(0);
                }
            }
            else 
                tmp.push_back(digits[i]);
        }
        // mean element was 9 add a 1
        if(tmp.back()==0)
            tmp.push_back(1);
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};