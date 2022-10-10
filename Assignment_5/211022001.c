#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int value)
{
    /* If the tree is empty, return a new Node */
    if (root == NULL)
        return newNode(value);

    /* Otherwise, recur down the tree */
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    /* return the (unchanged) Node pointer */
    return root;
}

void preordertraversal(struct Node *preorder)
{
    if (preorder != NULL)
    {
        printf("%d ", preorder->data);
        preordertraversal(preorder->left);
        preordertraversal(preorder->right);
    }
}

void inordertraversal(struct Node *inorder)
{
    if (inorder != NULL)
    {
        inordertraversal(inorder->left);
        printf("%d ", inorder->data);
        inordertraversal(inorder->right);
    }
}

void postordertraversal(struct Node *postordertravel)
{
    if (postordertravel != NULL)
    {
        postordertraversal(postordertravel->left);
        postordertraversal(postordertravel->right);
        printf("%d ", postordertravel->data);
    }
}

int maxValue(struct Node *max, int print)
{

    while (max->right != NULL)
    {
        max = max->right;
    }
    if(print)
        printf("Maximum value in BST is: %d \n", max->data);
    return max->data;
}

int minValue(struct Node *min, int print)
{
    while (min->left != NULL)
    {
        min = min->left;
    }
    if(print)
        printf("Minimum value in BST is: %d \n", min->data);
    return min->data;
}

struct Node *search(struct Node *root, int key,int print)
{

    while (root != NULL)
    {

        if (key == root->data)
        {
            if(print)
                printf("Element found %d \n", root->data);
            return root;
        }
        else if (key < root->data)
            root = root->left;
        else
        {
            root = root->right;
        }

    }
    if(print)
        printf("Element not found\n");
    return NULL;
}

void predecessor(struct Node *root, int key)
{
    struct Node *pred = search(root,key,0);
    if(pred==NULL)
    {
        printf("pred null");
        return;
    }
    if (pred->left != NULL)
    {
        int max  = maxValue(pred->left,0);
        printf("Predessor is %d \n", max);
    }
    return;
}

void successor(struct Node *root, int key)
{
    if(root ==NULL)
        return;
    
    if(root->data == key)
    {
        printf("Successor is %d ",)
    }
    // struct Node *suce = search(root,key,0);
    // printf("suc data %d \n",suce->data);
    // printf("suc r data %d \n",suce->right->data);
    // if(suce==NULL)
    //     return;
    
    // if (suce->right != NULL)
    // {
    //     int min = minValue(suce->right,0);
    //     printf("Succesor is %d \n", min);
    // }
    // return;
}



int main(int argc, char *argv[])
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("\n");
    preordertraversal(root);
    printf("\n");
    inordertraversal(root);
    printf("\n");
    postordertraversal(root);
    printf("\n");
    struct Node *add = search(root,30,1);
    // printf("%d \n",add->data);
    minValue(root,1);
    maxValue(root,1);
    predecessor(root,20);
    successor(root,40);
    return 0;
}