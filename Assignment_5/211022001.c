#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp_r, *fp_w;

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
    {
        root = newNode(value);
        fprintf(fp_w,"%d inserted\n", value);
    }

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
        fprintf(fp_w,"%d ", preorder->data);
        preordertraversal(preorder->left);
        preordertraversal(preorder->right);
    }
}

void inordertraversal(struct Node *inorder)
{
    if (inorder != NULL)
    {
        inordertraversal(inorder->left);
        fprintf(fp_w,"%d ", inorder->data);
        inordertraversal(inorder->right);
    }
}

void postordertraversal(struct Node *postordertravel)
{
    if (postordertravel != NULL)
    {
        postordertraversal(postordertravel->left);
        postordertraversal(postordertravel->right);
        fprintf(fp_w,"%d ", postordertravel->data);
    }
}

int maxValue(struct Node *max)
{

    while (max->right != NULL)
    {
        max = max->right;
    }

    fprintf(fp_w,"%d\n", max->data);
    return max->data;
}

int minValue(struct Node *min)
{
    while (min->left != NULL)
    {
        min = min->left;
    }

    fprintf(fp_w,"%d\n", min->data);
    return min->data;
}

struct Node *search(struct Node *root, int key)
{

    while (root != NULL)
    {

        if (key == root->data)
        {

            fprintf(fp_w,"%d found\n", root->data);
            return root;
        }
        else if (key < root->data)
            root = root->left;
        else
        {
            root = root->right;
        }
    }

    fprintf(fp_w,"%d not found\n", key);
    return NULL;
}

void succesor(struct Node *root, int key)
{

    struct Node *temp = root;
    while (temp != NULL)
    {
        if (key == temp->data)
        {

            struct Node *suc = NULL;
            while (root != NULL)
            {
                if (key >= root->data)
                    root = root->right;
                else
                {
                    suc = root;
                    root = root->left;
                }
            }
            if (suc != NULL)
                fprintf(fp_w,"%d\n", suc->data);
            return;
        }
        else if (key < temp->data)
            temp = temp->left;
        else
        {
            temp = temp->right;
        }
    }
    fprintf(fp_w,"%d does not exist\n", key);
    return;
}

void predessor(struct Node *root, int key)
{
    struct Node *temp = root;
    while (temp != NULL)
    {
        if (key == temp->data)
        {

            struct Node *pre = NULL;
            while (root != NULL)
            {
                if (key <= root->data)
                    root = root->left;
                else
                {
                    pre = root;
                    root = root->right;
                }
            }

            if (pre != NULL)
                fprintf(fp_w,"%d\n", pre->data);
            return;
        }
        else if (key < temp->data)
            temp = temp->left;
        else
        {
            temp = temp->right;
        }
    }
    fprintf(fp_w,"%d does not exist\n", key);
    return;
}

int main(int argc, char *argv[])
{
    fp_r = fopen(argv[1], "r");
    // fp_r = fopen("input1.txt", "r");
    fp_w = fopen("bst.txt", "w");
    struct Node *root = NULL;
    int i=0;

    char str[50];
    if (NULL == fp_r)
    {
        printf("Cannot_open \n");
    }
    while (fgets(str, 50, fp_r) != NULL)
    {
        char *token_1 = strtok(str, " ");
        // printf("%s\n",token_1);

        if (strcmp(token_1, "insert") == 0)
        {
            char *token_2 = strtok(NULL, " ");
            if(i==0)
            {
                root = insert(root,atoi(token_2));
                i=1;
            }
            else
                insert(root,atoi(token_2));
        }
        else if (strcmp(token_1, "inorder\n") == 0)
        {
            inordertraversal(root);
            fprintf(fp_w,"\n");

        }
        else if (strcmp(token_1, "preorder\n") == 0)
        {
            preordertraversal(root);
            fprintf(fp_w,"\n");
        }
        else if (strcmp(token_1, "postorder\n") == 0)
        {
            postordertraversal(root);
            fprintf(fp_w,"\n");
        }
        else if (strcmp(token_1, "search") == 0)
        {
            char *token_2 = strtok(NULL, " ");
            search(root,atoi(token_2));
        }
        else if (strcmp(token_1, "minimum\n") == 0)
        {
            minValue(root);
        }
        else if (strcmp(token_1, "maximum\n") == 0)
        {
            maxValue(root);
        }
        else if (strcmp(token_1, "successor") == 0)
        {
            char *token_2 = strtok(NULL, " ");
            succesor(root,atoi(token_2));
        }
        else if (strcmp(token_1, "predecessor") == 0)
        {
            char *token_2 = strtok(NULL, " ");
            predessor(root,atoi(token_2));
        }
        // else
        //     printf("Out of scope");
    }

    return 0;
}

// int main(int argc, char *argv[])
// {
//     // struct Node *root = NULL;
//     root = insert(root, 50);
//     insert(root, 30);
//     insert(root, 20);
//     insert(root, 40);
//     insert(root, 70);
//     insert(root, 60);
//     insert(root, 80);
//     preordertraversal(root);
//     printf("\n");
//     inordertraversal(root);
//     printf("\n");
//     postordertraversal(root);
//     printf("\n");
//     search(root,30);
//     minValue(root);
//     maxValue(root);
//     succesor(root,500);
//     // printf("%d \n",suc->data);
//     predessor(root,80);
//     // printf("%d \n",pre->data);
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     struct Node *root = NULL;
//     root = insert(root, 98);
//     postordertraversal(root);
//     printf("\n");
//     predessor(root, 53);
//     inordertraversal(root);
//     printf("\n");
//     search(root,37);
//     insert(root,0);
//     insert(root,38);
//     minValue(root);
//     postordertraversal(root);
//     printf("\n");
//     maxValue(root);
//     return 0;
// }
