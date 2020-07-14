#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node getNode(char data)
{
    node newNode=(node)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

node Insert(node root,char data)
{
    if(root==NULL)
    {
        root=getNode(data);
        return root;
    }
    if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

int Search(node root,char data)
{
    if(root==NULL)
        return -1;
    if(root->data==data)
        return 1;
    if(root->data<=data)
    {
        Search(root->left,data);
    }
    else
    {
        Search(root->right,data);
    }
}

void preorder(node root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    preorder(root->right);
         printf("%c ",root->data);
}

void inorder(node root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}

void postorder(node root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}


int main()
{
    node root=NULL;
    root=Insert(root,'f');
    root=Insert(root,'d');
    root=Insert(root,'j');
    root=Insert(root,'b');
    root=Insert(root,'e');
    root=Insert(root,'g');
    root=Insert(root,'k');
    root=Insert(root,'a');
    root=Insert(root,'c');
    root=Insert(root,'i');
    preorder(root);
    return 0;
}
