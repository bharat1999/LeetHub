// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    int totalOnes =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            totalOnes++;
    }
    if(totalOnes==0)
        return -1;
    vector<int> prefix(n);
    if(arr[0]==1)
        prefix[0]=1;
    for(int i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1]+arr[i];
    }
    // first window
    int zeroes = totalOnes - prefix[totalOnes-1];
    for(int i=totalOnes;i<n;i++)
    {
        int tmp = prefix[i]-prefix[i-totalOnes];
        zeroes = min(zeroes,totalOnes-tmp);
    }
    return zeroes;
    
}