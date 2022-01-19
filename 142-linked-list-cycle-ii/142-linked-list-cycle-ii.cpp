/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool isCycle(ListNode *head)
    {
       if(!head)
           return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!isCycle(head))
            return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        slow = head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};