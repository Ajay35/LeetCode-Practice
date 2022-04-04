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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* frontNode;
        ListNode* endNode = head;
        int ind = 1;
        while(temp != nullptr)
        {
            if(ind == k)
                frontNode = temp;
            if(ind > k)
                endNode = endNode->next;
            ind++;
            temp = temp->next;
        }
        swap(frontNode->val, endNode->val);
        return head;
    }
};