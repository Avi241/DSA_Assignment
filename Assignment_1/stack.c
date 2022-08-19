#include <stdio.h>
#include <stdlib.h>
int Top=-1,Stack_size,value;

void PUSH(int a[])
{

    if(Top!=Stack_size-1)
    {
        printf("Enter the value to be pushed : ");
        scanf("%d",&value);
        Top++;
        a[Top]=value;

    }
    else
        printf("Stack is full can't push");
}

void POP(int a[])
{
    if(Top!=-1)
    {
        printf("Element poped is %d \n",a[Top]);
        Top--;
    }
    else
        printf("Stack is empty");

}

void Display(int a[])
{
    int i=0;
    for(i=0;i<Stack_size;i++)
    {
        printf(" %d \n",a[i]);
    }
}

int main(int agrc,char *argv[])
{
    FILE *fp_w;
    fp_w = fopen("output.txt", "w"); // Write to file ,. 'a'-->append mode

    Stack_size = 5; //atoi(argv[1]);
    int a[Stack_size];

    PUSH(a);
    PUSH(a);
    PUSH(a);
    PUSH(a);
    PUSH(a);
    POP(a);
    PUSH(a);
    Display(a);
    fprintf(fp_w,"Push disk %d to Stack %s \n",5,"C");
    fprintf(fp_w,"Push disk %d to Stack %s \n",7,"A");



}
