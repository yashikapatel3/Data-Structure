#include<stdio.h>
#include<malloc.h>
struct Student
{
    int rollno;
    struct Student *next;
}*start;

void add()
{
    struct Student *ptr;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    printf("\nRoll no :");
    scanf("%d",&ptr->rollno);
    if(start==NULL)
    {
        start=ptr;
        ptr->next=start;
    }
    else
    {
        struct Student *p;
        p=start;
        while(p->next!=start)
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->next=start;

    }
}
void deleteNode()
{
    if(start==NULL)
        printf("\nNo Nodes Found");
    else{
        struct Student *ptr,*p;
        int no;
        printf("\nEnter Roll No to Delete");
        scanf("%d",&no);

    }

}
void show()
{
    struct Student *ptr;
    ptr=start;
    while(1)
    {
        printf("\nRoll No %d",ptr->rollno);
        printf("\n================");
        ptr=ptr->next;
        if(ptr==start)
            break;
    }
}
void main()
{
    start=NULL;
    int c;
    do
    {
        printf("\n1. Add a Node");
        printf("\n2. Show all Nodes");
        printf("\n3. Delete a Node");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            show();
        else if(c==3)
            deleteNode();
    }while(c!=3);
}
