#include<stdio.h>
#include<stdlib.h>

// Implementing a doubly linked list

// A doubly linked list is basically a bunch of nodes linked backwards and forwards.
// Each Node keeps track of the node behind it and in front of it as well as the data it contains.

// Let's think of a Linked List that is a list of numbers basically.

typedef struct Node {
    // The data in current node
    int data;
    // The previous node in DLL
    struct Node* prev;
    // The next node in DLL
    struct Node* next;
} Node;

Node* HEAD = NULL; // Start of the list
Node* TAIL = NULL; // End of the list

// Now we write a function to insert nodes in a DLL
// There are many ways to insert nodes in DLL
// 1. Insert in front of the list
// 2. Insert at the end of the list
// 3. Insert before a particular node
// 4. Insert after a particular node

Node* allocate_new_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void push(int data) {
    /*
    This function adds the node to the start of the list
    */

    // Allocate a new node
    Node* new_node = allocate_new_node(data);

    // Allocate next of the new_node to point towards the current head
    new_node->next = (HEAD);
    new_node->prev = NULL;

    // Make the previous of the current head point to new node
    if (HEAD != NULL) 
        HEAD->prev = new_node;

    // Make the new node the new head
    HEAD = new_node;
}

void append(int data) {
    // Allocate new node
    Node* new_node = allocate_new_node(data);

    // Allocate previous of new node to point towards to current TAIL
    new_node->prev = TAIL;
    new_node->next = NULL;

    // Make the next of the previous tail point to new node
    if (TAIL != NULL) 
        TAIL->next = new_node;
    
    // Make the new node the new tail
    TAIL = new_node;
}

void print() {
    Node *temp = HEAD;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(22); print();
    push(23); print();
    append(33); print();
    free();
}