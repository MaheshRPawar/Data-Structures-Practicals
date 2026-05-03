#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

// Create Tree
node* create()
{
    int x;
    cout<<"Enter value (-1 for no node): ";
    cin>>x;

    if(x==-1) return NULL;

    node* temp=new node;
    temp->data=x;

    cout<<"Enter left of "<<x<<endl;
    temp->left=create();

    cout<<"Enter right of "<<x<<endl;
    temp->right=create();

    return temp;
}

// Insert
node* insert(node* root,int x)
{
    if(root==NULL)
    {
        node* temp=new node;
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
node* findMin(node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

// Delete
node* deleteNode(node* root,int x)
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

        node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

// Search
bool search(node* root,int key)
{
    if(root==NULL) return false;

    if(root->data==key) return true;

    if(key<root->data)
        return search(root->left,key);
    else
        return search(root->right,key);
}

// Traversals
void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

// Count
int count(node* root)
{
    if(root==NULL) return 0;
    return 1+count(root->left)+count(root->right);
}

// Display
void display(node* root,int space)
{
    if(root==NULL) return;

    space+=5;

    display(root->right,space);

    cout<<endl;
    for(int i=5;i<space;i++) cout<<" ";
    cout<<root->data<<"\n";

    display(root->left,space);
}

int main()
{
    node* root;
    int ch,x;

    cout<<"Create Tree:\n";
    root=create();

    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Minimum\n8.Maximum\n9.Count\n10.Display\n11.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cin>>x;
                root=insert(root,x);
                break;

            case 2:
                cin>>x;
                root=deleteNode(root,x);
                break;

            case 3:
                cin>>x;
                if(search(root,x))
                    cout<<"Found";
                else
                    cout<<"Not Found";
                break;

            case 4: inorder(root); break;
            case 5: preorder(root); break;
            case 6: postorder(root); break;
            case 7: cout<<"Min: "<<findMin(root)->data; break;
            case 8:
            {
                node* ptr=root;
                while(ptr->right!=NULL)
                    ptr=ptr->right;
                cout<<"Max: "<<ptr->data;
                break;
            }
            case 9: cout<<"Count: "<<count(root); break;
            case 10: display(root,0); break;
        }

    }while(ch!=11);

    return 0;
}