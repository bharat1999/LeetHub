class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0, jumpSize = 0;
        for (i = 0; i < heights.size()-1; ++i)
        {
            jumpSize = heights[i+1] - heights[i];
            
            if (jumpSize <= 0) 
                continue;
            // use bricks
            bricks -= jumpSize;
            // add jumpSize
            pq.push(jumpSize);
            // if no bricks left use ladder
            if (bricks < 0)
            {
                bricks += pq.top();
                pq.pop();
                --ladders;
            }
            if (ladders < 0) 
                break;
        }
        return i;
    }
};