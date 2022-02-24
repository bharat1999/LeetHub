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
    ListNode* merge(ListNode* a,ListNode* b)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(a and b)
        {
            if(a->val<b->val)
            {
                cur->next = a;
                a = a->next;
            }
            else
            {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if(a)
            cur->next = a;
        if(b)
            cur->next = b;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *slow=head,*fast=head->next;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(fast);
        return merge(left,right);
    }
};