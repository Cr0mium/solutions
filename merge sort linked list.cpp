Node* merge(Node *a, Node *b)
    {
        Node *head=new Node(0);
        Node *res=head;
        while(a&&b)
        {
            if(a->data<b->data)
            {
                head->next=a;
                a=a->next;
            }
            else
            {
                head->next=b;
                b=b->next;
            }
            head=(head->next);
        }
        if(a) head->next=a;
        if(b) head->next=b;
        res=res->next;
        return res;
    }
    Node *sort(Node *head,int l,int r)
    {
        if(l==r-1) return head;
        
        Node *a=head,*p,*b=head;
        for(int i=l;i<(l+r+1)/2;++i)
        {   
            
            p=a,a=a->next;
            
        }
        p->next=NULL;
        b=sort(b,l,(l+r+1)/2);
        a=sort(a,(l+r+1)/2,r);
        Node *res=merge(b,a);
        return res;
    }
    Node* mergeSort(Node* head) {
        // your code here
        Node *x=head;
        int n=0;
        while(x)
        {
            x=x->next;
            ++n;
        }
        x = sort(head,0,n);
        return x;
    }
};
