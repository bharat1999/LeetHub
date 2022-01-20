class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++)
        {
            vector<int> fre(10);
            for(int j=0;j<9;j++)
            {
                if(b[i][j]=='.')
                    continue;
                if(fre[b[i][j]-'0']>0)
                    return false;
                fre[b[i][j]-'0']++;
            }
        }
        for(int i=0;i<9;i++)
        {
            vector<int> fre(10);
            for(int j=0;j<9;j++)
            {
                if(b[j][i]=='.')
                    continue;
                if(fre[b[j][i]-'0']>0)
                    return false;
                fre[b[j][i]-'0']++;
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                vector<int> fre(10);
                int si = (i / 3) * 3;
	            int sj = (j / 3) * 3;
                for (int k = si ; k < si + 3; k++) 
                {
		            for (int l = sj; l < sj + 3; l++) 
                    {
			            if(b[k][l]=='.')
                            continue;
                        if(fre[b[k][l]-'0']>0)
                            return false;
                        fre[b[k][l]-'0']++;
	                }
	            }   
            }
        }
        return true;
    }
};