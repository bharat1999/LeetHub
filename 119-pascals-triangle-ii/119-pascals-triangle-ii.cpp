class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> v(r+1,1);
        long temp=1;
        int num = r;
        int den = 1;
        for(int i=1;i<r;i++)
        {
            temp = (temp*num)/den;
            v[i]=temp;
            num--;
            den++;
        }
        return v;
    }
};