
#include<stdio.h>
#include<malloc.h>
struct Student
{
    int rollno;
    struct Student *prev, *next;
}*start, *end;

struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
     if(ptr==NULL)
    {
        printf("\nCannot Allocate Memory");
        return NULL;
    }
    else
    {
        printf("\nRoll No : ");
        scanf("%d",&ptr->rollno);
        return ptr;
    }
};

void addBeg()
{
    struct Student *ptr;
    ptr=createNode();
    if(start==NULL)
    {
        start=ptr;
        end=ptr;
        ptr->next=ptr;
        ptr->prev=ptr;
    }
    else
    {
        ptr->next=start;
        ptr->prev=end;
        start->prev=ptr;
        end->next=ptr;
        start=ptr;
    }
}
addMiddle()
{
    struct Student *ptr,*p;
    int no;
    printf("\nEnter a Roll No after which you need to add");
    scanf("%d",&no);
      if(start==NULL)
    {
        ptr=createNode();
        start=ptr;
        end=ptr;
        ptr->next=ptr;
        ptr->prev=ptr;
    }
    else
    {
        for(p=start;p!=end;p->next=start)
        {
            if(p->rollno==no)
                    ptr=createNode();
                    ptr->next=p->next;
                    ptr->prev=p;
                    ptr->next->prev=ptr;
                    p->next=ptr;
        }
    }
}
void addEnd()
{
    struct Student *ptr;
    ptr=createNode();
    if(start==NULL)
    {
        start=ptr;
        end=ptr;
        ptr->next=ptr;
        ptr->prev=ptr;
    }
    else
    {
        ptr->next=start;
        ptr->prev=end;
        end->next=ptr;
        end=ptr;
    }
}

void traverse()
{
    struct Student *ptr;
    if(start==NULL)
    {
        printf("\nNo Nodes Found");
    }
    ptr=start;
    do
    {
        printf("\n%d",ptr->rollno);
           ptr=ptr->next;
    }
    while(ptr!=start);
}

void reverseTraverse()
{
 struct Student *ptr;
    if(start==NULL)
    {
        printf("\nNo Nodes Found");
    }
    ptr=end;
    do
    {
        printf("\n%d",ptr->rollno);
           ptr=ptr->prev;
    }
    while(ptr!=end);
}
void del()
{

}
void main()
{
    start=end=NULL;
    int c;
    do
    {
        printf("\n1. Add a Node at the beginning");
        printf("\n2. Add a Node at the Middle (Specific Position)");
        printf("\n3. Add a Node at the End");
        printf("\n4. Traverse");
        printf("\n5. Reverse Traverse");
        printf("\n6. Delete a Node");
        printf("\n7. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMiddle();
        else if(c==3)
           addEnd();
        else if(c==4)
            traverse();
        else if(c==5)
            reverseTraverse();
        else if(c==6)
            del();
    }while(c!=7);
}
