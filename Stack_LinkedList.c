#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = top;

    top = temp;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is Empty");
        return;
    }

    struct node *temp = top;

    printf("Deleted: %d",top->data);

    top = top->next;

    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack Empty");
        return;
    }

    printf("Top element: %d",top->data);
}

void isEmpty()
{
    if(top == NULL)
        printf("Stack is Empty");
    else
        printf("Stack not Empty");
}

void display()
{
    struct node *ptr = top;

    while(ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

int main()
{
    int ch,x;

    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.isEmpty");
        printf("\n5.Display");
        printf("\n6.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                display();
                break;
        }

    }while(ch!=6);

    return 0;
}