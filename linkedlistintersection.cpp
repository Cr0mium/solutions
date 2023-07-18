Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *x=NULL,*ans=NULL;
    while(head1 && head2)
    {
        if(head1->data == head2->data)
        {
            struct Node *res=new struct Node(head1->data);
            //res->next=x;
            //x=res;
            if(!ans) {x=res;ans=x;}
            else
            {
                x->next=res;
                x=x->next;
            }
            head1=head1->next;
            head2=head2->next;
        }
        else if (head1->data<head2->data)
        {
            head1=head1->next;
        }
        else
            head2=head2->next;
    }
    //cout<<ans->next->next;
    return ans;
}
