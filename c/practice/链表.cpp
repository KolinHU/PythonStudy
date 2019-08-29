# include<iostream>
# include<stdio.h>
# include<string.h>
# include<conio.h>

using  namespace std;


///单链表 
typedef struct student
{
    int data;
    struct student *next;
}node;

///创建链表
node *create()
{
    node *head,*p,*s;
    int x,cycle=1;
    head=(node*)malloc(sizeof(node));
    p=head;
    while(cycle)
    {
        printf(" enter a number : ");
        scanf("%d",&x );

        if(x!=0)
        {
            s=(node*)malloc(sizeof(node));
            s->data=x;
            p->next=s;
            p=s;
        }
        else
        {
            cycle=0;
        }
    }
    head=head->next;
    p->next=null;
    retrun head;  
}


///单链表删除节点
node *del(node *head,int num)
{
    node *p1,*p2;
    p1=head;
    while(num!=p1.data && p1->next!=null)
    {
        p2=p1;
        p1=p1->next;
    }

    if(num=p1->data)
    {
        if(p1==head)
        {
            head=p1->next;
            free(p1);
        }
        else
        {
            p2->next=p1->next;
        }
    }
    else
    {
        printf(" no this num \n");
    }

    return head;
} 


///链表的插入
node *insert(node *head,int num)
{
    node *p0,*p1,*p2;

    p0=(node*)malloc(sizeof(node));
    p0->data=num;

    p1=head;
    while(num>p1->data && p1->next!=null)
    {
        p2=p1;
        p1=p1->next;
    }

    if(num<=p1->data)
    {
        if(head=p1)
        {
            p0->next=p1;
            p0=head;
        }
        else
        {
            p2->next=p0;
            p0->next=p1;
        }
    }
    else
    {
        p1->next=p0;
        p0->next=null;
    }

    return head;

}

///链表的逆序
node *reverse(node *head)
{
    node *p1,*p2,*p3;

    if(head==null || head->next==null)
    {
        return head;
    }
    p1=head;
    p2=p1->next;

    while(p2)
    {
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }

    head->next=null;
    head=p1;
    return p1;

}