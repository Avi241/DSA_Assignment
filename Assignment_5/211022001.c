#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;

void insert(int value)
{
    struct Node *new_node=NULL;
    struct Node *current=NULL;
    struct Node *temp=NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left=NULL;
    new_node->right==NULL;
    if(root==NULL)
        root=new_node;
        
    current=root;
    while (current!=NULL)
    {
        temp=current;
        if(current->data > new_node->data)
            current=current->left;
        else
            current=current->left;
    }
    if (temp->data > new_node->data)
        temp->left=new_node;
    else
        temp->right=new_node;    

}

void preordertraversal(struct Node *preorder)
{
    if(preorder!=NULL)
    {
        printf("%d ",preorder->data);
        preordertraversal(preorder->left);
        preordertraversal(preorder->right);
    }
}

void inordertraversal(struct Node *inorder)
{
    if(inorder!=NULL)
    {
        inordertraversal(inorder->left);
        printf("%d ",inorder->data);
        inordertraversal(inorder->right);
    }
}

int main(int argc, char *argv[])
{
    insert(5);
    insert(67);
    insert(10);
    insert(20);
    insert(3);
    insert(1);
    insert(30);
    printf("\n");
    preordertraversal(root);
    printf("\n");
    inordertraversal(root);


    printf("\n");
    return 0;


}