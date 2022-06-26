class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> temp(8);
        n = n%14==0?14:n%14;
        while(n--)
        {
            for(int i=1;i<7;i++)
                temp[i]= cells[i-1]==cells[i+1]?1:0;
            for(int i=0;i<8;i++)
                cells[i]=temp[i];
        }
        return cells;
    }
};