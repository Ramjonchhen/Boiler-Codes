#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

struct Node* getNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=NULL;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insert(int data)
{
    if(root==NULL)
    {
       root=getNode(data);
       return;
    }
    struct Node* travelNode=root;
    struct Node* secondLastNode;

    while(travelNode!=NULL)
    {
        secondLastNode=travelNode;
        if(data<=travelNode->data)
        {
            travelNode=travelNode->left;
        }
        else
        {
            travelNode=travelNode->right;
        }
    }
    if(data<=secondLastNode->data)
    {
        secondLastNode->left=getNode(data);
    }
    else
    {
        secondLastNode->right=getNode(data);
    }
}

int search(int data)
{
    struct Node* travelNode=root;
    while(travelNode!=NULL)
    {
        if(travelNode->data=data)
        {
            return 1;
        }
        if(data<=travelNode->data)
        {
            travelNode=travelNode->left;
        }
        else
        {
            travelNode=travelNode->right;
        }
    }
        return 0;
}

int main()
{
    root=NULL;
    insert(5);
    insert(4);
    insert(3);
    insert(7);
    if(search(7))
        printf("Element found");
    else
        printf("Element Not Found");
    return 0;
}
