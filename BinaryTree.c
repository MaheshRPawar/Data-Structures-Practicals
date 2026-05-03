#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create Tree
struct node* create()
{
    int x;
    printf("Enter value (-1 for no node): ");
    scanf("%d",&x);

    if(x == -1)
        return NULL;

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    printf("Enter left child of %d\n",x);
    temp->left = create();

    printf("Enter right child of %d\n",x);
    temp->right = create();

    return temp;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void search(struct node *root,int key)
{
    if(root == NULL)
        return;

    if(root->data == key)
        printf("\nElement Found");

    search(root->left,key);
    search(root->right,key);
}

int count(struct node *root)
{
    if(root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int main()
{
    struct node *root;

    root = create();

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    int key;
    printf("\nEnter element to search: ");
    scanf("%d",&key);

    search(root,key);

    printf("\nTotal nodes: %d",count(root));

    return 0;
}