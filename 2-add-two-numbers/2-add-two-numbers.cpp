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
    ListNode* sum(ListNode* h1,ListNode* h2)
    {
        ListNode head(-1);
        ListNode* dummy = &head;
        int carry = 0;
        while(h1 and h2)
        {
            int sum = (h1->val+h2->val+carry)%10;
            carry = (h1->val+h2->val+carry)/10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1)
        {
            int sum = (h1->val+carry)%10;
            carry = (h1->val+carry)/10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            h1 = h1->next;
        }
        while(h2)
        {
            int sum = (h2->val+carry)%10;
            carry = (h2->val+carry)/10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            h2 = h2->next;
        }
        if(carry)
            dummy->next = new ListNode(carry);
        return head.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        head=sum(l1,l2);
        return head;
        
    }
};