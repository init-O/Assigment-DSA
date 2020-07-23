#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int stack[MAX];
int n;
int counter=-1;
void push(int value)
{
    counter++;
    stack[counter] = value;
    printf("The stack has been updated\n\n");
}

void pop()
{
    printf("The value at the Top os the stack is : %d\n",stack[counter]);
    counter--;
    printf("The stack has been updated\n\n");
}

void status()
{
    int pos = n-1-counter;
    if(counter == n-1)
        printf("The stack is full\n\n");
    else if (counter == -1)
        printf("The stack is empty\n\n");
    else
        printf("%d data can still be stored in the stack\n\n",pos);}

int main()
{
    int value,c,choice;
    printf("Enter the size of the stack : ");
    scanf("%d",&n);
    printf("Enter 1 to continue with the operations and 0 to exit..... : ");
    scanf("%d",&c);
    while(c)
    {
        printf("ENTER : \n[1].To push element in the stack\n");
        printf("[2]. To pop element from stack\n[3]. To view the stack status\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            if(counter == n-1)
                printf("Cannot push data in the stack as the stack is full\n\n");
            else{
                printf("Enter the data to be pushed into the stack : ");
                scanf("%d",&value);
                push(value);
            }
            break;
        case 2 :
            if(counter == -1)
                printf("The stack is already empty\n\n");
            else pop();
            break;
        case 3 :
            status();
            break;
        case 4 :
            printf("You might want to consider your options again\n\n");
            break;
        }
        printf("Enter 1 to continue with the operations and 0 to exit..... : ");
        scanf("%d",&c);
    }
}

