class Solution {
    int ans;
    void solve(int n,int i,int size)
    {
        if(size == n)
        {
            ans++;
            return;
        }
        if(size>n or i>5)
            return;
        //take same vowel
        solve(n,i,size+1);
        // take current and go to next vowel
        solve(n,i+1,size);
        
    }
public:
    int countVowelStrings(int n) {
        ans = 0;
        solve(n,1,0);
        return ans;      
    }
};