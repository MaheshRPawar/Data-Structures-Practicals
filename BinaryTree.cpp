#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

// Create Tree using user input
node* create()
{
    int x;
    cout<<"Enter value (-1 for no node): ";
    cin>>x;

    if(x == -1)
        return NULL;

    node *temp = new node;
    temp->data = x;

    cout<<"Enter left child of "<<x<<endl;
    temp->left = create();

    cout<<"Enter right child of "<<x<<endl;
    temp->right = create();

    return temp;
}

// Inorder
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// Preorder
void preorder(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder
void postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

// Search
void search(node *root,int key)
{
    if(root == NULL)
        return;

    if(root->data == key)
        cout<<"\nElement Found";

    search(root->left,key);
    search(root->right,key);
}

// Count Nodes
int count(node *root)
{
    if(root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int main()
{
    node *root;

    root = create();

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPreorder: ";
    preorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    int key;
    cout<<"\nEnter element to search: ";
    cin>>key;

    search(root,key);

    cout<<"\nTotal nodes: "<<count(root);

    return 0;
}