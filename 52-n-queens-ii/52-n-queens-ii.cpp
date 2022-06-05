class Solution {
    int ans;
	bool isValid(int r,int c,vector<string>&v,int n)
    {
		//column check 
		for(int i=0;i<=r;i++)
			if(v[i][c]=='Q') 
                return false;
        
		//diagonal check upper left side
		int row=r,col=c;
		while(row>=0 and col>=0)
        {
			if(v[row--][col--]=='Q') 
                return false;
        }
            
		//diagonal check upper right side
		row=r,col=c;
		while(row>=0 and col<n)
        {
			if(v[row--][col++]=='Q') 
                return false;
		}
            
		return true;
	}
	void helper(int r,vector<string> &v,int n)
    {
		if(r==n)
        {   //if row reaches end of the board 
			ans++;
			return ;
		}
		for(int i=0;i<n;i++)
        {  //fixing row and traversing in column
			if(isValid(r,i,v,n))
            {
				v[r][i]='Q';
				helper(r+1,v,n);
				v[r][i]='.';
			}
		}
	}
    public:
    int totalNQueens(int n) {
        ans= 0;
        vector<string> v;
		string s(n,'.');
		for(int i=0;i<n;i++) 
            v.push_back(s);
		helper(0,v,n);
		return ans;
    }
};