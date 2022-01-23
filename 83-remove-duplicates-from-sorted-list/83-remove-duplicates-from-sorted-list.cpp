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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *tail=head,*cur=head;
        while(cur)
        {
            while(tail->val==cur->val and cur->next)
            {
                cur=cur->next;
            }
            if(cur->val == tail->val) // means last element is same as current
            {    
                tail->next=NULL;
                return head;
            }
            tail->next = cur;
            tail=tail->next;
        }
        return head;
    }
};