/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n=0,m=0;
    Node *a=head1;
    while(a)
    {
        ++n;
        a=a->next;
    }
    Node *b=head2;
    while(b)
    {
        ++m;
        b=b->next;
    }
    //iterate through loop till equal number of element are left towards the end
    a=head1,b=head2;
    while(n>m){a=a->next;--n;}
    while(m>n){b=b->next;--m;}
    
    while(a!=b)
    {
        a=a->next;
        b=b->next;
    }
    if(a) return a->data;
    else    return -1;
}

