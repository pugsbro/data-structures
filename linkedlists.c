#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data){
/* function will push node onto head of array list 
o(1) complexity insert 
*/

 /* 
 ** is used to change the value of the pointer rather than the value of the node itself 
 */ 
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

    new_node -> data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(struct Node *n){
/* function that will print linked list content starting at given node*/
    while (n!=NULL){
        printf("%d", n->data);
        n = n->next;
    }
}

void append(struct Node** head_ref, int new_data){
    /* given a reference to the head of the list, append a new node at the end*/
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node -> data = new_data;

    new_node -> next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;

}

void insertAfter(struct Node* prev_node, int new_data){
    /* given a node insert a new node after the given one */
    /* pointer to pointer is not required here as you are declaring the new pointer within the function*/
    if(prev_node == NULL){
        printf("previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = new_data;

    new_node -> next = prev_node -> next;

    prev_node ->next = new_node;




}

int main()
{
    struct Node* head = NULL;
  
    append(&head, 1);
    push(&head, 999);
    insertAfter(head, 666);


    printList(head);

    return 0;

}