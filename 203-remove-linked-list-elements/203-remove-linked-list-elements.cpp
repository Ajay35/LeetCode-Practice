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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        
        while(head != nullptr and head->val == val) {
            head = head->next;
        }
        
        while(cur != nullptr) {
            
           if(cur->next != nullptr and cur->next->val == val) {
               ListNode* cur_next = cur->next;
               while(cur_next != nullptr and cur_next->val == val) {
                   cur_next = cur_next->next;
               }
               
               cur->next = cur_next;
           }
            
           cur = cur->next;
        }
            
    
        return head;
    }
};