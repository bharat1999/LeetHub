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
    int length(ListNode* h)
    {
        int len = 0;
        while(h)
        {
            len++;
            h=h->next;
        }
        return len;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        if(len%2 and len/2 +1 ==k)
            return head;
        ListNode *start = head,*end = head;
        int count=1;
        while(count<k)
        {
            start = start -> next;
            count++;
        }
        count = 1;
        while(count<=len-k)
        {
            count++;
            end = end->next;
        }
        swap(start->val,end->val);
        return head;
    }
};