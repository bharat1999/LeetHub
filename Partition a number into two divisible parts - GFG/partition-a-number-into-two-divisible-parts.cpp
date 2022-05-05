// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        int n=0,idx=-1;
        char x;
        for(int i=0,s=S.size();i<s;i++)
        {
            x = S[i];
            n = n*10 + (x-'0');
            if(n%a==0 and i!=s-1) 
            {
                string c = S.substr(i+1);
                int y = stoi(c);
                if(y%b)
                    continue;
                idx=i;
                break;
            }
        }
        if(idx==-1 or idx==S.size()-1)
            return "-1";
        string ans = S.substr(0,idx+1);
        ans+=" "+S.substr(idx+1);
        return ans;   
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends