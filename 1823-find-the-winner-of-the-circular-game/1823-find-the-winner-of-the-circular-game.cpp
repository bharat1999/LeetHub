class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
            q.push(i);
        while(q.size()>1)
        {
            int t = k-1;
            // Adding K-1 elements at end of queue
            while(t--)
            {
                q.push(q.front());
                q.pop();
            }
            // Deleting kth player
            q.pop();
        }
        return q.front();
    }
};