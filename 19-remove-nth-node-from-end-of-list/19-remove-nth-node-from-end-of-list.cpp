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
    int length(ListNode *head)
    {
        int count=0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int to_delete = length(head) - n; // element to be deleted from front
        ListNode *prev=NULL,*cur=head;
        for(int i=1;i<=to_delete;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        if(!prev) // when we have to delete first element
            return cur->next;
        prev->next = cur->next;
        return head;
    }
};