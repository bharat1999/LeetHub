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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(list1 and list2)
        {
            if(list1->val < list2->val)
            {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }
        while(list1)
        {
            cur->next = list1;
            cur = cur->next;
            list1 = list1->next;
        }
        while(list2)
        {
            cur->next = list2;
            cur = cur->next;
            list2 = list2->next;
        }
        return head->next;
    }
};