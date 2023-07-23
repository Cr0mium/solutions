/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

void partition(node **start,node **end)
{
    if(*start==*end) return;
    node *c=*start,*p=*start;
    node *last=*end;
    while(c!=*end)
    {
        if(c->data > (*end)->data)
        {
            if(p==c)
            {
                c=c->next;
                p->next=last->next;
                last->next=p;
                *start=c;
                p=c;
            }
            else
            {
                p->next=c->next;
                c->next=last->next;
                last->next=c;
                c=p->next;
            }
            last=last->next;
        }
        else
        {
            p=c;
            c=c->next;
        }
    }
    node *x=*start;
    partition( start,&p);
    if(*end!=last)// if pivot is last and not element were added after that
        partition(&(*end)->next,&last);
}

void quickSort(struct node **headRef) {
    node *x=*headRef;
    while(x->next)
    {
        x=x->next;
    }
    partition(headRef,&x);
}
