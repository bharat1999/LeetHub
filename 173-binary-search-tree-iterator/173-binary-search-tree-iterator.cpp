/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode *temp;
    stack<TreeNode*> st;
    void pushInStack(TreeNode* root)
    {
        temp = root;
        while(temp)
        {
            st.push(temp);
            temp = temp->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushInStack(root);
    }
    
    int next() {
        auto x = st.top();
        st.pop();
        pushInStack(x->right);
        return x->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */