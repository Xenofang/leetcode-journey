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
    ListNode* reverseRight(ListNode* right)
    {
        

        ListNode* prev = NULL;
        ListNode* curr = right;

        while(curr!= NULL)
        {
            ListNode* agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr= agla;
        }
        return prev;
        
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next!= NULL)
        {
            fast= fast->next->next;
            slow = slow->next;
        }
        

        ListNode* lhead = head;
        ListNode* right = slow->next;

        slow->next = NULL;

        // prev is out new head means reverse  right half
        ListNode* rhead = reverseRight(right);

        // connecting left head and right head

        ListNode* lcurr = lhead;
        ListNode* rcurr = rhead;

        while(lcurr != NULL && rcurr != NULL)
        {
            ListNode* lnext = lcurr->next;
            ListNode* rnext = rcurr->next;

            lcurr->next = rcurr;
            lcurr = lnext;

            rcurr->next = lcurr;
            rcurr = rnext;
        }

        
    }
};