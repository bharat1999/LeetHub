class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(),t.end());
        int ans = 0;
        int score = 0;
        int n = t.size();
        if(n==1)
        {
            if(power>=t[0])
                return 1;
            return 0;
        }
        int s = 0;
        int e = n-1;
        while(s<=e and ( power>=t[s] or score>0))
        {
            while(s<=e and power>=t[s])
            {
                power-=t[s++];
                score++;
            }
            ans = max(ans,score);
            if(s<=e and score>0)
            {  
                power+=t[e--];
                score--;
            }
        }
        return ans;
    }
};