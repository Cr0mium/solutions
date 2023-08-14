Node* reverseDLL(Node * head)
{
    //Your code here
    
    Node *x,*p,*n=head;
    while(n)
    {
        x=n;
        n=x->next;
        x->next=p;
        p=x;
    }
    head->next=NULL;
    Node* newhead=x;
    n=newhead;
    while(n)
    {
        x=n;
        n=x->prev;
        x->prev=p;
        p=x;
    }
    newhead->prev=NULL;
    return newhead;
}
