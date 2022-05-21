class Solution {
    bool check(int d,vector<int> &pos,int m)
    {
        int lastPos = pos[0];
        int cows = 1;
        for(int i=1,n=pos.size();i<n;i++)
        {
            if(pos[i]-lastPos>=d)
            {
                cows++;
                lastPos=pos[i];
            }
        }
        return cows>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s = 0;
        int e = position[position.size()-1];
        while(s<e)
        {
            int mid = e - (e-s)/2;
            if(check(mid,position,m))
                s = mid;
            else
                e = mid - 1;
        }
        return s;
    }
};