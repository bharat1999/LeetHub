class Solution {
public:
    int nxt(int i, char dir) {
        if (dir=='R') return i+1;
        return i-1; 
    }
    char rev(char dir) {
        if (dir == 'L') return 'R';
        return 'L'; 
    }
    string pushDominoes(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++) ans += '.'; 
        vector<int> dist(n,-1); 
        deque <int> q;
        for (int i = 0; i < n; i++) {
            if (s[i] != '.') {
                ans[i] = s[i]; 
                dist[i] = 0; 
                q.push_back(i);
            }
        }
        while(!q.empty()) {
            int j = nxt(q[0], ans[q[0]]);
            if (j >= 0 and j < n) {
                if (ans[j] == '.') {
                    ans[j] = ans[q[0]]; 
                    q.push_back(j);
                    dist[j] = dist[q[0]]+1;
                }
                else if (ans[j] != '.' and ans[j] == rev(ans[q[0]]) and dist[j] == dist[q[0]]+1) {
                    ans[j] = '.'; 
                }
            }
            q.pop_front(); 
        }
        return ans; 
    }
};