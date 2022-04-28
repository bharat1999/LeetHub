class Solution
{
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool isvalid(int x, int y, int n, int mid)
    {
        return (x >= 0 and x < n and y >= 0 and y < mid); 
    }


    bool bfs(vector<vector<int>> heights, int k)
    {
        queue<pair<int, int>> q;
        q.push({0, 0}); 
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        // make a visisted array initially with all the value false initially 
        visited[0][0] = true;

        while (!q.empty())
        {
            pair<int, int> curr = q.front(); 
            q.pop();
            int cx = curr.first;
            int cy = curr.second;
            if (cx == heights.size() - 1 and cy == heights[0].size() - 1)
                return true;
            // if we are reached the last index we are done
            // else just go in all 4 direction and check conditions  
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + cx;
                int y = dy[i] + cy;
                // each time make new x , y 
                if (isvalid(x, y, heights.size(), heights[0].size()) && !visited[x][y])
                {
                    // if that x,y is valid , just check tah absolute difference is less tha tha mid or not 
                    if (abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        visited[x][y] = true;
                        // if yes visit that node 
                        q.push({x, y});
                        // push it in queue 
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {

        int low = 0;
        int high = 1e6;
        int ans = -1;


        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (bfs(heights, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};