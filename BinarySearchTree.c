#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

// Create
struct node* create()
{
    int x;
    printf("Enter value (-1 for no node): ");
    scanf("%d",&x);

    if(x==-1) return NULL;

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;

    printf("Enter left of %d\n",x);
    temp->left=create();

    printf("Enter right of %d\n",x);
    temp->right=create();

    return temp;
}

// Insert
struct node* insert(struct node* root,int x)
{
    if(root==NULL)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->left=temp->right=NULL;
        return temp;
    }

    if(x<root->data)
        root->left=insert(root->left,x);
    else if(x>root->data)
        root->right=insert(root->right,x);

    return root;
}

// Min
struct node* findMin(struct node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

// Delete
struct node* deleteNode(struct node* root,int x)
{
    if(root==NULL) return NULL;

    if(x<root->data)
        root->left=deleteNode(root->left,x);
    else if(x>root->data)
        root->right=deleteNode(root->right,x);
    else
    {
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;

        struct node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

// Search
int search(struct node* root,int key)
{
    if(root==NULL) return 0;

    if(root->data==key) return 1;

    if(key<root->data)
        return search(root->left,key);
    else
        return search(root->right,key);
}

// Traversals
void inorder(struct node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

// Count
int count(struct node* root)
{
    if(root==NULL) return 0;
    return 1+count(root->left)+count(root->right);
}

// Display
void display(struct node* root,int space)
{
    if(root==NULL) return;

    space+=5;

    display(root->right,space);

    printf("\n");
    for(int i=5;i<space;i++) printf(" ");
    printf("%d\n",root->data);

    display(root->left,space);
}

int main()
{
    struct node* root;
    int ch,x;

    printf("Create Tree:\n");
    root=create();

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Min\n8.Max\n9.Count\n10.Display\n11.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: scanf("%d",&x); root=insert(root,x); break;
            case 2: scanf("%d",&x); root=deleteNode(root,x); break;
            case 3:
                scanf("%d",&x);
                if(search(root,x)) printf("Found");
                else printf("Not Found");
                break;
            case 4: inorder(root); break;
            case 5: preorder(root); break;
            case 6: postorder(root); break;
            case 7: printf("Min: %d",findMin(root)->data); break;
            case 8:
            {
                struct node* ptr=root;
                while(ptr->right!=NULL) ptr=ptr->right;
                printf("Max: %d",ptr->data);
                break;
            }
            case 9: printf("Count: %d",count(root)); break;
            case 10: display(root,0); break;
        }

    }while(ch!=11);

    return 0;
}