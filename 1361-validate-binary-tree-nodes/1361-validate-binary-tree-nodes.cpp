class Solution {
    vector<int> parent;
    int find(int p)
    {
        if(parent[p]==p)
            return p;
        return parent[p] = find(parent[p]);
    }
    bool Union(int a,int b)
    {
        int pa = find(a);
        int pb = find(b);
        // if b already have a parent means it can be access by more than one node so return false
        if(pb!=b)
            return false;
        // if child and parent have same parent means it have a back edge means cycle
        if(pa==pb)
            return false;
        // otherwise set paret of child as i
        parent[b] = pa;
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                if(!Union(i,leftChild[i]))
                    return false;
            }
            if(rightChild[i]!=-1)
            {
                if(!Union(i,rightChild[i]))
                    return false;
            }
        }
        int tree = 0;
        // now we will calculate number of tree
        for(int i=0;i<n;i++)
            if(parent[i]==i)
                tree++;
        // if more than one node is parent of itself means more than 1 tree
        return tree==1;
        
    }
};