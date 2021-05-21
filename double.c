#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev,*next;
};
struct node *head=NULL,*ptr;

void insert_begin(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)//checking empty or not
    {
        head=temp;//list is empty
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;                  //list is not empty
    }
    
}

void insert_end(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
}

void insert_position(int value,int ele)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        ptr=head;
        while(ptr!= NULL)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next->prev=temp;
        ptr->next=temp;
    }
}


void delete_beg()
{
if(head==NULL)
    {
        printf("List is empty we can not delete ");
        
    }
    else
    {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        head->prev=NULL;
        free(ptr);
    }
}
    void delete_end()
    {
        if(head==NULL)
        {
        printf("List is empty we can not delete ");
        }
    
    else
    {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            free(ptr);
    }

    }
void delete_nposition(int ele)
{
    if(head==NULL)
        {
        printf("List is empty we can not delete ");
        }
    
    else
    {
        while(ptr->data!=ele)
        {
            ptr=ptr->next;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev= ptr->prev;
        ptr->next=NULL;
        ptr->prev=NULL;
        free(ptr);
    
}

void display()
{
    if(head==NULL)
        {
        printf("List is empty we can not delete ");
        }
    
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d<=>",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void main()
{
    int value,ele,ch;
    printf("1. Insert_beg\n");
    printf("2. Insert_end\n");
    printf("3. Insert_nposition\n");
    printf("4. deletion_beg\n");
    printf("5. deletion_end\n");
    printf("6. deletion_nposition\n");
    printf("7. exit\n");

    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                 printf("Enter the value\n");
                scanf("%d",&value);
                insert_begin(value);
                display();
                break;
            }
            case 2:
            {
                 printf("Enter the value\n");
                scanf("%d",&value);
                insert_end(value);
                display();
                break;
            }
            case 3:
            {
                 printf("Enter the element\n");
                scanf("%d",&ele);
                insert_position(value,ele);
                display();
                break;
            }
            case 4:
            {
                 delete_beg();
                 display();
                 break;
            }
            case 5:
            {
                 printf("Enter the value\n");
                scanf("%d",&value);
                delete_end(value);
                display();
                break;
            }
            case 6:
            {
                 printf("Enter the element\n");
                scanf("%d",&ele);
                delete_nposition(value);
                display();
                break;
            }
            case 7:
            {
                exit(0);
            }
        }
    }
}
}