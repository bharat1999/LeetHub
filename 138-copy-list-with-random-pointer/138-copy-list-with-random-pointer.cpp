/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // key = old, value = new
        unordered_map<Node*,Node*> oldToNew;
        Node *cur = head;
        Node *newHead = new Node(-1);
        Node *cur2 = newHead;
        while(cur)
        {
            if(oldToNew.count(cur)==0)
                oldToNew[cur] = new Node(cur->val);
            if(cur->random and oldToNew.count(cur->random)==0)
               oldToNew[cur->random] = new Node(cur->random->val);
            cur = cur->next;
        }
        cur = head;
        while(cur)
        {
            cur2->next = oldToNew[cur];
            cur2=cur2->next;
            if(cur->random)
                cur2->random = oldToNew[cur->random];
            cur=cur->next;
        }
        return newHead->next;
    }
};