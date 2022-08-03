class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
                inDegree[leftChild[i]]++;
            if(rightChild[i]!=-1)
                inDegree[rightChild[i]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(inDegree[i]==0)
                q.push(i);
        // more than one tree
        if(q.size()!=1)
            return false;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(leftChild[cur]!=-1)
            {
                inDegree[leftChild[cur]]--;
                if(inDegree[leftChild[cur]]<0)
                    return false;
                q.push(leftChild[cur]);
            }
            if(rightChild[cur]!=-1)
            {
                inDegree[rightChild[cur]]--;
                if(inDegree[rightChild[cur]]<0)
                    return false;
                q.push(rightChild[cur]);
            }
            topo.push_back(cur);
        }
        // if topo order have n nodes mean only one tree
        if(topo.size()==n)
            return true;
        return false;
    }
};