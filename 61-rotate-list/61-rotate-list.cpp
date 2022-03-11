/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)
            return head;
        ListNode *h=head;
        ListNode *t = head;
        int count = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            count++;
        }
        k%=count;
        ListNode *prev=NULL;
        while(k--)
        {
            t = h;
            prev = NULL;
            while(t->next)
            {
                prev = t;
                t = t->next; 
            }
            t->next=h;
            h = t;;
            prev->next = NULL;
            t = prev;
        }
        return h;
        
    }
};