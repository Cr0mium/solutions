class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void split(Node *head,Node **a, Node **b)
    {
        Node *fast=head,*slow=head;
        while(fast->next)
        {
            fast=fast->next;
            if(fast->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        *a=head;
        *b=slow->next;
        slow->next=NULL;
    }
    Node* mergeList(Node *a,Node *b)
    {
        if(!a) return b;
        if(!b) return a;
        Node *res;
        if(a->data<=b->data)
            res=a,res->next=mergeList(a->next,b);
        else
            res=b,res->next=mergeList(a,b->next);
        return res;
        
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !(head->next)) return head;
        Node *a,*b;
        split(head,&a,&b);
        a=mergeSort(a);//142 
        b=mergeSort(b);
        head=mergeList(a,b);
        return head;
    }
};
