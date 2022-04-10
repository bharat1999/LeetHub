class Solution {
public:
    int calPoints(vector<string>& ops) {
        // to simulate stack as it has clear function
        vector<int> st;
        for(auto x:ops)
        {
            if(x=="+")
            {
                int t1 = st.back();
                st.pop_back();
                int t2 = st.back();
                st.push_back(t1); 
                st.push_back(t1+t2);
            }
            else if(x=="D")
                st.push_back(2*st.back());
            else if(x=="C") 
                st.pop_back();
            else
                st.push_back(stoi(x));   
        }
        int sum=0;
        for(auto x:st)
            sum+=x;
        return sum;
    }
};