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
        ListNode* temp = head;
        ListNode* endNode = head;
        ListNode* prevEndNode = head;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        int cur = 1;
        while(temp != nullptr)
        {
            if(cur > n)
            {
                prevEndNode = endNode;
                endNode = endNode->next;
            }
            cur++;
            temp = temp->next;
        }
        if(prevEndNode == endNode)
            dummy->next = prevEndNode->next;
        else
            prevEndNode->next = endNode->next;
        return dummy->next;
    }
};