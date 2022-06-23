bool cmp(vector<int> &a,vector<int> &b)
{
    if(a[1]!=b[1])
        return a[1]<b[1];
    return a[0]<a[0];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> maxHeap;
        sort(courses.begin(),courses.end(),cmp);
        int curTime = 0;
        for(auto x:courses)
        {
            curTime+=x[0];
            maxHeap.push(x[0]);
            if(curTime>x[1])
            {
                curTime-=maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};