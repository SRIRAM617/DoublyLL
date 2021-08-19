#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;
void Create(int A[],int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node *));
    first->prev=first->next=NULL;
    first->data=A[0];
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;

        last=t;


    }
}
void display(struct Node *p)
{
        while(p)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
}
int length(struct  Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

int insert(struct Node *p,int index,int element)
{
    struct Node *tt;int i;
    if(index>length(first)||index<0)
    {
        return -1;
    }
    else if(index==1)
    {
         if(p->next==p)
         {
           tt=(struct Node *)malloc(sizeof(struct Node));
         tt->data=element;
             tt->next=p;
            tt->prev=p->prev;
            p->prev=tt;
            p->next=NULL;
            first=tt;

         }

         tt=(struct Node *)malloc(sizeof(struct Node));
         tt->data=element;
             tt->next=p;
            tt->prev=p->prev;
            p->prev=tt;
            first=tt;


    }
    else{
        tt=(struct Node *)malloc(sizeof(struct Node));
        tt->data=element;
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        tt->next=p->next;
    p->next=tt;
        tt->prev=p;
    }
}
int deleteDL(struct Node *p,int index)
{
    int x,i;
    if(index==1)
    {

        first=first->next;
        x=p->data;
        if(first){first->prev=NULL;}

        free(p);

    }

    else{

            for(i=0;i<index-1;i++){p=p->next;}
            x=p->data;
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }

        free(p);

    }
     return x;

}
void Reverse(struct Node *p)
{
    struct Node *t;

    while(p)
    {
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p!=NULL&&p->next==NULL){first=p;}
    }


}



int main()
{
    int A[]={1,2,3,4,5};

    Create(A,5);
     Reverse(first);
    display(first);


    return 0;
}
