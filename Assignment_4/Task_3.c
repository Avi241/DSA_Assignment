#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp_r, *fp_w_dll;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head_dll = NULL;

void insert(int value)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    fprintf(fp_w_dll,"inserted %d\n",value);
    temp->data=value;
    temp->next=NULL;
    if(head_dll==NULL)
        temp->prev=NULL;
    else
    {
        temp->prev=head_dll;
        head_dll->next=temp;
    }
    
    head_dll = temp;

}

void delete(int check_var)
{
    struct Node *temp = NULL;
    struct Node *temp_head = NULL;
    temp = head_dll;

    while (temp != NULL)
    {
        if (temp->data == check_var)
        {
            if(temp==head_dll)
            {
                (temp->prev)->next=NULL;
                head_dll=temp->prev;
                fprintf(fp_w_dll,"deleted %d\n", check_var);
                free(temp);
                return;
            }

            if(temp->prev!=NULL)
                (temp->prev)->next=temp->next;

            if(temp->next != NULL)
                (temp->next)->prev=temp->prev;

            fprintf(fp_w_dll,"deleted %d\n", check_var);
            free(temp);

            return;
        }
        temp = temp->prev;
    }
    fprintf(fp_w_dll,"cannot delete %d\n",check_var);
    
}

void query_d(int check_var)
{
    struct Node *temp;

    // Check for stack underflow
    // if (top == NULL)
    // {
    //     printf("Stack Underflow \n");
    // }
    // else
    {
        temp = head_dll;
        while (temp != NULL)
        {
            if (temp->data == check_var)
            {
                fprintf(fp_w_dll,"found %d\n", check_var);
                return;
            }
            temp = temp->prev;
        }
    }
    fprintf(fp_w_dll,"not found %d\n", check_var);
}

void display_d()
{
    struct Node *temp;

    // Check for stack underflow
    if (head_dll == NULL)
    {
        fprintf(fp_w_dll,"\n");
        return;
    }
    else
    {
        temp = head_dll;
        while (temp != NULL)
        {
            fprintf(fp_w_dll,"%d ", temp->data);
            temp = temp->prev;
        }
        fprintf(fp_w_dll,"\n");
    }
}

int main(int argc, char *argv[])
{
    // Max_Stack_Size = atoi(argv[2]);
    fp_r = fopen(argv[1], "r");
    fp_w_dll = fopen("output.txt", "w");
    char str[50];
    if (NULL == fp_r)
    {
        printf("Cannot_open \n");
    }
    while (fgets(str, 50, fp_r) != NULL)
    {
        // printf("%s", str);
        char *token_1 = strtok(str, " ");
        switch(token_1[0])
        {
        case '+':
        {
            char *token_2 = strtok(NULL, " ");
            insert(atoi(token_2));
            break;
        }

        case '-':
        {
            char *token_2 = strtok(NULL, " ");
            delete(atoi(token_2));
            break;
        }

        case '?':
        {
            char *token_2 = strtok(NULL, " ");
            query_d(atoi(token_2));
            break;
        }

        case '!':
            display_d();
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
        }

        // printf("%s \n", token_1);
        // char *token_2 = strtok(NULL, " ");
        // if (token_2 != NULL)
        //     printf("%s", token_2);
    }


    // insert(5);
    // insert(3);
    // insert(6);
    // display();
    // delete(3);
    // display();
    // insert(4);
    // display();
    // delete(4);
    // // query(3);
    // // query(7);
    // insert(2);
    // display();

    printf("\n");

    return 0;
}