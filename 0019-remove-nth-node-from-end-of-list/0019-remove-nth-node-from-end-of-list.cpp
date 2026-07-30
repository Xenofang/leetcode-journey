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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head ;
        ListNode* fast = head;

        if(head->next == NULL && n>1)
        {
            head = NULL;
            return head;                
        }

        while(n > 0)
        {
            fast = fast->next;
            n--;
        }
        if(fast == NULL )
        {
            ListNode* len = head;
            head = head->next;
            delete len;
            return head;
        }
        

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        del->next = NULL;
        delete del;
        

        return head;

    }
};