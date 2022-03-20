class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int mx;
        vector<int> freq(6);
        for(auto x:tops)
            freq[x-1]++;
        for(auto x:bottoms)
            freq[x-1]++;
        bool possible = false;
        for(int i=0;i<6;i++)
        {
            if(freq[i]>=n)
            {
                mx = i+1;
                possible = true;
                break;
            }
        }
        
        if(!possible)
            return -1;
        cout<<mx<<endl;
        bool topPossible = true;
        int swap1 = 0;
        for(int i=0;i<n;i++)
        {
            if(tops[i]==mx)
                continue;
            else if(bottoms[i]==mx)
                swap1++;
            else
            {
                topPossible = false;
                break;
            }
        }
        bool bottomPossible = true;
        int swap2 = 0;
        for(int i=0;i<n;i++)
        {
            if(bottoms[i]==mx)
                continue;
            else if(tops[i]==mx)
                swap2++;
            else
            {
                bottomPossible = false;
                break;
            }
        }
        if(!bottomPossible and !topPossible)
            return -1;
        if(!bottomPossible)
            return swap1;
        if(!topPossible)
            return swap2;
        return min(swap1,swap2);
    }
};