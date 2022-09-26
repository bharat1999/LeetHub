class Solution {
    vector<int> parent;
    int find_parent(int i)
    {
        if(parent[i] == -1)
            return i;
        return parent[i] = find_parent(parent[i]); 
    }
    
    void Union(int a,int b)
    {
        int parentA = find_parent(a);
        int parentB = find_parent(b);
        if(parentA != parentB)
            parent[parentA] = parentB;
    }
public:
    bool equationsPossible(vector<string>& equations) 
    {
        // 26 as atmax 26 characters
        parent.resize(26,-1);
        for(int i = 0;i<equations.size();i++)
        {
            // if both are equal make union
            if(equations[i][1] == '=')
                Union(equations[i][0]-'a',equations[i][3]-'a');
        }
        for(int i = 0;i<equations.size();i++)
        {
            // if a!=b but they are in same set mean b == a given than its false
            if(equations[i][1] == '!')
            {
                if(find_parent(equations[i][0]-'a') == find_parent(equations[i][3] - 'a') )
                    return false;
            }
        }
        return true;
    }
};