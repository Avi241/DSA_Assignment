#include <stdio.h>
#include <stdlib.h>

int Stack_size;

struct  Stack
{
    char name;
    int top;
    int* a;
};



void push(struct Stack *s,int n,FILE *fp_w)
{
    if(s->top!=Stack_size-1)
    {
        fprintf(fp_w,"Push disk %d to Stack %c\n",n,s->name);
        s->top++;
        s->a[s->top]=n;
    }
    else
        return;
}

void pop(struct Stack *s,FILE *fp_w)
{
    if(s->top!=-1)
    {
        fprintf(fp_w,"Pop disk %d from Stack %c\n",s->a[s->top],s->name);
        s->a[s->top]=0;
        s->top--;
    }
    else
        return;
}

void Display(struct Stack *s)
{
    printf("Elements in stack %c are \n",s->name);
    int i=0;
    for(i=0;i<Stack_size;i++)
    {
        printf(" %d \n",s->a[i]);
    }
}

void towerOfHanoi(int n, struct Stack *A,
                    struct Stack *B, struct Stack *C,FILE *fp_w) 
{ 
    if (n == 0) 
    {
        return; 
    } 
    towerOfHanoi(n - 1, A, C, B,fp_w); 
    pop(A,fp_w);
    push(C,n,fp_w);
    towerOfHanoi(n - 1, B, A, C,fp_w); 
}

void intialize(struct Stack *A,FILE *fp_w)
{
    for(int i=Stack_size;i>0;i--)
    {
        push(A,i,fp_w);
    }

}

struct Stack A,B,C;

int main(int agrc,char *argv[])
{
    FILE *fp_w;
    Stack_size = atoi(argv[1]);
    // char buffer[100];
    // snprintf(buffer,100,"toh-%d.txt",Stack_size);
    fp_w = fopen("toh.txt", "w");

    
    A.name='A';
    A.top=-1;
    A.a=calloc(Stack_size,sizeof(int));

    B.name='B';
    B.top=-1;
    B.a=calloc(Stack_size,sizeof(int));

    C.name='C';
    C.top=-1;
    C.a=calloc(Stack_size,sizeof(int));

    intialize(&A,fp_w); // 

    // Display(&A);
    // Display(&C);

    towerOfHanoi(Stack_size,&A,&B,&C,fp_w);

    // printf("############################################### \n");
    // printf("After Tower of Hanoi \n");
    // printf("############################################### \n");

    // Display(&A);
    // Display(&C);

    free(A.a);
    free(B.a);
    free(C.a);

    return 0;
}