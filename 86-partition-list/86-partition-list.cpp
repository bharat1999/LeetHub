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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return NULL;
        ListNode *dummy1=new ListNode(-1);
        ListNode *dummy2=new ListNode(-1);
        ListNode *l1 = dummy1;
        ListNode *l2 = dummy2;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->val<x)
            {
                l1->next = cur;
                cur=cur->next;
                l1=l1->next;
                l1->next = NULL;
            }
            else
            {
                l2->next= cur;
                l2=l2->next;
                cur = cur->next;
                l2->next=NULL;
            }
        }
        l1->next = dummy2->next;
        return dummy1->next;
    }
};