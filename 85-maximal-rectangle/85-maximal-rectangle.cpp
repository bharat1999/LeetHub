class Solution {
    int largestHistogram(vector<int> &h)
    {
        int n = h.size();
        vector<int> prevSmall(n),nextSmall(n);
        
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and h[st.top()]>=h[i])
                st.pop();
            // if stack empty mean all to left are greater
            if(st.empty())
                prevSmall[i] = -1;
            // if not empty top element is smaller
            else
                prevSmall[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and h[st.top()]>=h[i])
                st.pop();
            // if stack empty mean all to left are greater
            if(st.empty())
                nextSmall[i] = n;
            // if not empty top element is smaller
            else
                nextSmall[i] = st.top();
            st.push(i);
        }
        int area =0;
        for(int i=0;i<n;i++)
        {
            int l = h[i];
            int b = nextSmall[i] - prevSmall[i] - 1;
            area = max(area,l*b);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> h(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                h[i][j] = mat[i][j]-'0';
        }
        int ans = largestHistogram(h[0]);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(h[i][j])
                    h[i][j]+=h[i-1][j];
            }
            ans = max(ans,largestHistogram(h[i]));
        }
        return ans;
    }
};