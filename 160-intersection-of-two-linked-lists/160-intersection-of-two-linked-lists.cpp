/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode *head)
    {
        int count = 0;
        while(head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        ListNode *t1 = headA , *t2 = headB;
        if(l1>=l2)
        {
            int dif = l1-l2;
            while(dif--)
                t1 = t1->next;
        }
        else
        {
            int dif = l2-l1;
            while(dif--)
                t2 = t2->next;
        }
        while(t1 and t2 and t1!=t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};