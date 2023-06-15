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
  //recursion
    ListNode* rec(ListNode* head) {
        if(head->next)
        {
            ListNode* cur=rec(head->next);
            head->next->next=head;
            return cur;
        }
        return head;
    }
  //iterate
    ListNode* itr(ListNode* head) {
        ListNode *cur=head,*n,*p;
        n=head;
        while(n)
        {
            p=cur;
            cur=n;
            n=cur->next;
            cur->next=p;
        }
        return cur;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* cur= itr(head);
        head->next=NULL;
        return cur;
    }
};
