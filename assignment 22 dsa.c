#include <stdio.h>
#include <stdlib.h>
#define ll long long
int n;
    //user defined datatype for creating node
struct node
{
    char name[20],branch[20];
    ll sem,number;
    struct node *next;
};
struct node *head=NULL,*temp;

       //function to create a node and return a
            //pointer to the address of the node created
struct node* create_node(void)
{
        struct node* newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the name : ");
        scanf("%s",&newnode->name);
        printf("Enter branch : ");
        scanf("%s",&newnode->branch);
        printf("Enter semester : ");
        scanf("%d",&newnode->sem);
        printf("Enter phone number : ");
        scanf("%d",&newnode->number);
        newnode->next=NULL;
        return newnode;
};

        //creating initial linked list
void create(void)
{
    for(int i=0;i<n;i++)
    {
        printf("\nenter the details of student %d \n",i+1);
        struct node* newnode;
        newnode = create_node();
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("\nThe linked list with student details has been created \n\n");
}

        //dynamic linking of nodes at start or end of the linked list
void add(int c)
{
    struct node *newnode;
    newnode = create_node();
    n++;
    switch(c)
    {
    case 1 :
        newnode->next=head;
        head=newnode;
        printf("The node has been added in the front of the linked list\n\n");
        break;
    case 2 :
        temp = head;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next = newnode;
        printf("The node has been added in the end of the linked list\n\n");
        break;
    }
}
        //dynamic deletion of a node from start or end
void del(int c)
{
    n--;
    switch(c)
    {
    case 1:
        temp = head;
        head = head->next;
        free(temp);
        printf("The node at the beginning has been erased\n\n");
        break;
    case 2 :
        temp = head ;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        printf("The node at the end has been erased\n\n");
        break;
    }
}

        //function to return the current number of nodes in the linked list
int curr_number(void)
{
    printf("The current number of nodes in the linked list is : %d\n\n",n);
}

        //displaying all the data in the linked list
void display(void)
{
    temp=head;
    for(int i=0;i<n;i++)
    {
        printf("Details of student %d \n",i+1);
        printf("Name : %s\n",temp->name);
        printf("Branch : %s\n",temp->branch);
        printf("semester : %d\n",temp->sem);
        printf("contact : %d\n\n",temp->number);
        temp=temp->next;
    }
}

        //driver function
int main()
{
        printf("Enter the initial number of students : ");
        scanf("%d",&n);
        create();
        int c,choice;
        printf("Enter 1 to continue with the operations : ");
        scanf("%d",&c);
        while(c)
        {
            printf("Enter :\n(1).To enter a node at the start\n");
            printf("(2).To insert node at end\n");
            printf("(3).To delete node at the start\n(4).To delete node at the end\n");
            printf("(5).To display the current linked list\n(6).To get node count\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1 :
                add(1);
                break;
            case 2 :
                add(2);
                break;
            case 3 :
                del(1);
                break;
            case 4 :
                del(2);
                break;
            case 5 :
                display();
                break;
            case 6 :
                curr_number();
                break;
            default :
                printf("you might want to consider your choices again \n");
                break;
            }
            printf("\n");
            printf("Enter 1 if you want to continue with the operations : ");
            scanf("%d",&c);
            printf("\n\n\n");
        }
}
