/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // To keep track of nodes whose cope is made
    // here key is the node of OG graph and value is the same value new node to be added
    // as we have to made copy of all nodes
    unordered_map<Node*,Node*> cloned;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* clone = new Node(node -> val);
        cloned[node] = clone;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) 
        {
            Node* cur = q.front();
            q.pop();
            for (auto x : cur -> neighbors) 
            {
                // if current node not cloned before clone it and add to queue
                if (cloned.find(x) == cloned.end()) 
                {
                    // creating new node 
                    cloned[x] = new Node(x -> val);
                    q.push(x);
                }
                //in current node push adjcant node
                cloned[cur] -> neighbors.push_back(cloned[x]);
            }
        }
        return clone;
    }
};