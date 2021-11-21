class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        ListNode *KSizeChecker = head;
        for(int i=0;i<k;i++)
        {
            if(KSizeChecker==NULL)
                return head;
            KSizeChecker = KSizeChecker->next;
        }
        int cnt=0;
        ListNode *cur=head,*prev=NULL,*next=NULL;
        while(cur and cnt<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            cnt++;
        }
        if(next)
            head->next=reverseKGroup(next,k);
        return prev;
    }
};