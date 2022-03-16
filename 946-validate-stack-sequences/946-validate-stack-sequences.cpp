class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i=0;
        int j=0;
        while(i<n and j<n)
        {
            if(pushed[i]==popped[j])
            {
                i++;
                j++;
            }
            else if(!st.empty() and st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }   
        }
        while(j<n)
        {
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
                return false;
        }
        return true;
    }
};