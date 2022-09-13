#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Max_Stack_Size;
int stack_size = 0;
int Max_Queue_Size;
int queue_size = 0;
FILE *fp_r, *fp_w, *fp_w_q, *fp_w_dll;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *head_dll = NULL;

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
    free(temp);
}

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

// Driver's code
int main(int argc, char *argv[])
{
    Max_Stack_Size = atoi(argv[2]);
    Max_Queue_Size = atoi(argv[2]);
    // Max_Queue_Size = 25;
    // Max_Stack_Size = 25;
    fp_r = fopen(argv[1], "r");
    // fp_r = fopen("input.txt", "r");
    fp_w = fopen("stack.txt", "w");
    fp_w_q = fopen("queue.txt", "w");
    fp_w_dll = fopen("dll.txt","w");
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
            enqueue(atoi(token_2));
            insert(atoi(token_2));
            break;
        }

        case '-':
        {
            char *token_2 = strtok(NULL, " ");
            pop();
            dequeue();
            delete(atoi(token_2));
            break;
        }

        case '?':
        {
            char *token_2 = strtok(NULL, " ");
            query(atoi(token_2));
            query_q(atoi(token_2));
            query_d(atoi(token_2));
            break;
        }

        case '!':
            display();
            display_q();
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