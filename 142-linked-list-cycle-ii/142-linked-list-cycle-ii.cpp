/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        auto slow=head,fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) // if at ay point both are same mean cycle exist
                return true;
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head or !hasCycle(head))
            return NULL;   
        auto slow=head,fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) // if at ay point both are same mean cycle exist
                break;
        }
        slow=head;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};