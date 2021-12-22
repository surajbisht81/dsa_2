// creation of binary tree;
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* create()
{
    int data;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the data of node:");
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    temp->data=data;
    printf("\nenter the left child of %d:",data);
    temp->left=create();
    printf("\nenter the right child of %d:",data);
    temp->right=create();
    return temp;
}
void inorder(struct node *temp)
{
    if(!temp)
        return;
    inorder(temp->left);
    printf("\t%d",temp->data);
    inorder(temp->right);
}
void preorder(struct node* temp)
{
    if(!temp)
        return;
    printf("\t%d",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct node *temp)
{
    if(!temp)
        return ;
    postorder(temp->left);
    postorder(temp->right);
    printf("\t%d",temp->data);
}
int main()
{
    struct node *root;
    root=(struct node*)malloc(sizeof(struct node));
    printf("\ncreation of binary tree.");
    root=create();
    printf("\ntree is created.\n");
    int choice;
    while(1)
    {
     printf("\n1.inorder traversal \n2.preorder traversal \n3.post order traversal \n4.exit");
     printf("\n\nenter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        inorder(root);
        break;
     case 2:
        preorder(root);
        break;
     case 3:
        postorder(root);
        break;
     case 4:
        exit(0);
        break;
     default:
        printf("\nenter valid option.");
        break;
     }
}
}
