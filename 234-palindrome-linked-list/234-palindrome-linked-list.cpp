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
    // helper function to reverse list after mid
    ListNode* reverse(ListNode* head, ListNode* prev) 
    {
        if(!head->next)
            return head;    
        ListNode* next;
        while(head) 
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return true;
        
        ListNode* slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reversing list after mid
        ListNode* head2 = reverse(slow->next, NULL);
        slow->next = NULL;

        while(head2) 
        {
            if(head2->val != head->val)
                return false;
            head2 = head2->next;
            head = head->next;
        }
        
        return true;
    }
    
    
};