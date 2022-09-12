#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int *next;
};

int main()
{
    struct Node head, second, third;

    head.data = 5;
    head.next = &second.data;

    second.data = 5;
    second.next = &third.data;

    third.data = 5;

    third.next = NULL;

    printf("%p \n ", second.next);
    printf("%p \n ", head.next);

    return 0;
}