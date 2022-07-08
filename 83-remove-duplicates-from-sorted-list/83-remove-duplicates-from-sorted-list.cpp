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
        
        ListNode* cur = head;
        
        while(cur != nullptr) {
            
            ListNode* cur_next = cur;
            
            while(cur_next != nullptr and cur_next->val == cur->val) {
                cur_next = cur_next->next;
            }
            
            cur->next = cur_next;
            cur = cur->next;
        }
        
        return head;
    }
};