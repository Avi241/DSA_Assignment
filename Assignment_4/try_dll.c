#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head_dll = NULL;


void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}


void insert(int value)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("inserted %d\n",value);
    /* 2. put in the data  */
    temp->data = value;
 
    /* 3. Make next of new node as head_dll and previous as NULL
     */
    temp->next = head_dll;
    temp->prev = NULL;
 
    /* 4. change prev of head_dll node to new node */
    if (head_dll != NULL)
        head_dll->prev = temp;
 
    /* 5. move the head_dll to point to the new node */
    head_dll = temp;

}

int main()
{
    insert(5);
    return 0;
}