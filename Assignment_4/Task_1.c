#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Max_Stack_Size;
int stack_size = 0;
FILE *fp_r, *fp_w;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void query(int check_var)
{
    struct Node *temp;

    // Check for stack underflow
    // if (top == NULL)
    // {
    //     printf("Stack Underflow \n");
    // }
    // else
    {
        temp = top;
        while (temp != NULL)
        {
            if (temp->data == check_var)
            {
                fprintf(fp_w,"found %d\n", check_var);
                return;
            }
            temp = temp->next;
        }
    }
    fprintf(fp_w,"not found %d\n", check_var);
}

void display()
{
    struct Node *temp;

    // Check for stack underflow
    if (top == NULL)
    {
        fprintf(fp_w,"\n");
        return;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            fprintf(fp_w,"%d ", temp->data);
            temp = temp->next;
        }
        fprintf(fp_w,"\n");
    }
}

void push(int value)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    // printf("%d %d",stack_size,Max_Stack_Size);
    if (stack_size >= Max_Stack_Size)
    {
        fprintf(fp_w,"overflow\n");
    }
    else
    {
        stack_size++;
        fprintf(fp_w,"pushed %d\n",value);
        temp->data = value;
        temp->next = top;
        top = temp;

        // free(temp);
    }
}

void pop()
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    stack_size--;
    if (top == NULL)
    {
        printf("Stack Underflow Nothing to pop \n");
    }
    else
    {
        temp = top;
        fprintf(fp_w,"popped %d\n", temp->data);
        top = top->next;
    }
}

// Driver's code
int main(int argc, char *argv[])
{
    Max_Stack_Size = atoi(argv[2]);
    fp_r = fopen(argv[1], "r");
    fp_w = fopen("output.txt", "w");
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
            push(atoi(token_2));
            break;
        }

        case '-':
            pop();
            break;

        case '?':
        {
            char *token_2 = strtok(NULL, " ");
            query(atoi(token_2));
            break;
        }

        case '!':
            display();
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


    // push(5);
    // push(3);
    // push(6);
    // pop();
    // push(4);
    // query(3);
    // query(7);
    // push(2);
    // display();

    printf("\n");

    return 0;
}