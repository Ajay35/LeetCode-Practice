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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
 
        ListNode* prev;
        while (fast_ptr != NULL and fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            prev = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        prev->next = slow_ptr->next;
        delete slow_ptr;

        return head;
    }
};