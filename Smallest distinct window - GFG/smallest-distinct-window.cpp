// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_set<char> st1;
        for(auto x:str)
            st1.insert(x);
        unordered_map<char,int> st2;
        int n = str.size();
        int s = 0;
        int e = 0;
        int ans = INT_MAX;
        while(e<n)
        {
            st2[str[e]]++;
            if(st1.size()==st2.size())
            {
                while(st2[str[s]]>1)
                    st2[str[s++]]--;
                ans=min(ans,e-s+1);
            }
            e++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends