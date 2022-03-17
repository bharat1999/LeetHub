class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int score=0;
        for(auto x:s)
        {
         //if we find open parenthesis, push the current score into the stack   
            if(x=='(')
            {
                //add score till current level
                st.push(score);
                // we reset score of currrent depth
                score=0;
            }//if we find close parenthesis
            else if(x==')')
            {
                // it will be max of 2*score and 1 bcz for () score =0;
                score=st.top()+ max(2* score , 1);
                st.pop();
            }
        }
        return score;
    }
};