/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        ListNode endNode = head;
        ListNode prevEndNode = head;
        ListNode dummy = new ListNode();
        dummy.next = head;
        int cur = 1;
        while(temp != null)
        {
            if(cur > n)
            {
                prevEndNode = endNode;
                endNode = endNode.next;
            }
            cur++;
            temp = temp.next;
        }
        if(prevEndNode == endNode)
            dummy.next = prevEndNode.next;
        else
            prevEndNode.next = endNode.next;
        return dummy.next;
    }
}