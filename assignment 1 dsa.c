
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 10000001
    int n;
    int arr[MAX];
         //function to create the array
    void create(void)
    {
        if(n>MAX)
            printf("you've gone too far with the numbers buddy \n");
        else{
            printf("Enter the elements of the array : ");
            for(int i=0;i<n;i++)
            {
                printf("element %d : ",i+1);
                scanf("%d",&arr[i]);
            }
            printf("The array has been created \n");
        }
    }

          //adding element to a given position
    void pos(void)
    {
        int posi,value;
        printf("\n\nenter the position you want to add an element to : ");
        scanf("%d",&posi);
        printf("Enter the value of element to be added : ");
        scanf("%d",&value);
        for(int i=n-1;i>=posi-1;i--)
        {
            arr[i+1] = arr[i];
        }
        arr[posi-1]=value;
        n++;
        printf("The element has been inserted at position %d \n\n",posi);
    }
           //displaying the elements of array
    void display(void)
    {
        printf("\n\nDisplaying the elements of the array : \n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
           //deleting the elements of array at particular position
    void del(void)
    {
        int position;
        printf("\n\nenter the position where you want to delete element : ");
        scanf("%d",&position);
        for(int i=position-1;i<n-1;i++)
        {
            arr[i] = arr[i+1];
        }
        n--;
        printf("The element at position %d has been deleted \n\n",position);
    }

            //driver function
    int main()
    {
        printf("Enter the initial number of elements in the array that you want to create : ");
        scanf("%d",&n);
        create();
        int c,choice;
        printf("Enter 1 to continue with the operations : ");
        scanf("%d",&c);
        while(c)
        {
            printf("Enter :\n(1).To enter an element at position i\n");
            printf("(2).To display the elements stored in the array\n(3).To delete the element at position i : ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1 :
                pos();
                break;
            case 2 :
                display();
                break;
            case 3 :
                del();
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
