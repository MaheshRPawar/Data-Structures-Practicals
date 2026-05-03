#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

void push(int x)
{
    node *temp = new node;

    temp->data = x;
    temp->next = top;

    top = temp;
}

void pop()
{
    if(top == NULL)
    {
        cout<<"Stack is Empty";
        return;
    }

    node *temp = top;

    cout<<"Deleted: "<<top->data;

    top = top->next;

    delete temp;
}

void peek()
{
    if(top == NULL)
    {
        cout<<"Stack Empty";
        return;
    }

    cout<<"Top element: "<<top->data;
}

void isEmpty()
{
    if(top == NULL)
        cout<<"Stack is Empty";
    else
        cout<<"Stack not Empty";
}

void display()
{
    node *ptr = top;

    while(ptr != NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }

    cout<<"NULL";
}

int main()
{
    int ch,x;

    do
    {
        cout<<"\n1.Push";
        cout<<"\n2.Pop";
        cout<<"\n3.Peek";
        cout<<"\n4.isEmpty";
        cout<<"\n5.Display";
        cout<<"\n6.Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>x;
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