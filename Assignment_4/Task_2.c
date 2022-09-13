#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Max_Queue_Size;
int queue_size = 0;
FILE *fp_r, *fp_w_q;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    // printf("%d %d",stack_size,Max_Stack_Size);
    if (queue_size >= Max_Queue_Size)
    {
        fprintf(fp_w_q,"overflow\n");
    }
    else
    {
        queue_size++;
        fprintf(fp_w_q,"enqueued %d\n",value);
        temp->data = value;
        if(front==NULL)
        {
            front=temp;
            rear=temp;
            front->next=NULL;
            rear->next=NULL;
        }
        else
        {
            rear -> next = temp;  
            rear = temp;  
            rear->next = NULL;
        }

        // free(temp);
    }
}

void dequeue()
{
    struct Node *temp = NULL;
    queue_size--;
    if (front == NULL)
    {
        printf("Stack Underflow Nothing to pop \n");
    }
    else
    {
        temp = front;
        fprintf(fp_w_q,"dequeued %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void query_q(int check_var)
{
    struct Node *temp;

    // Check for stack underflow
    // if (top == NULL)
    // {
    //     printf("Stack Underflow \n");
    // }
    // else
    {
        temp = front;
        while (temp != NULL)
        {
            if (temp->data == check_var)
            {
                fprintf(fp_w_q,"found %d\n", check_var);
                return;
            }
            temp = temp->next;
        }
    }
    fprintf(fp_w_q,"not found %d\n", check_var);
}

void display_q()
{
    struct Node *temp;

    // Check for stack underflow
    if (front == NULL)
    {
        fprintf(fp_w_q,"\n");
        return;
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            fprintf(fp_w_q,"%d ", temp->data);
            temp = temp->next;
        }
        fprintf(fp_w_q,"\n");
    }
}


int main(int argc, char *argv[])
{
    Max_Queue_Size = atoi(argv[2]);
    fp_r = fopen(argv[1], "r");
    fp_w_q = fopen("output.txt", "w");
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
            enqueue(atoi(token_2));
            break;
        }

        case '-':
            dequeue();
            break;

        case '?':
        {
            char *token_2 = strtok(NULL, " ");
            query_q(atoi(token_2));
            break;
        }

        case '!':
            display_q();
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
    // query_q(3);
    // query_q(7);
    // push(2);
    // display_q();

    printf("\n");

    return 0;
}