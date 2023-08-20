Node* reverseDLL(Node * head)
{
    //Your code here
    
    Node *c,*p=NULL,*n=head;
    while(n)
    {
        x=n;
        n=c->next;
        c->next=p;
        c->prev=n;
        p=c;
    }
    head->next=NULL;
    Node* newhead=x;
    return newhead;
}
