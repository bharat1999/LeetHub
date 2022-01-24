class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans = INT_MIN;
        int left_max = v[0]; // v[0] + 0
	    for(int j=1; j<v.size(); j++)
        {
            
		    int score = left_max + v[j] - j; // first update score
		    ans = max(ans, score);
            // it will be updated after calculating score
            // bcz if done before than left and right can be same
            // means i==j which is not allowed
            left_max = max(left_max,v[j] + j); //v[j]+j bcz left part = v[i] + i
        }
        return ans;
    }    
};