//
//  main.c
//  Lab1-5-BBower16
//
//  Created by Baylor K. Bower on 3/7/19.
//  Copyright © 2019 Baylor K. Bower. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    L I N K E D   L I S T
*/

//Initial stuct
struct node{
    int data;
    int key;
    struct node *next;
};

//Creating pointers for Head and Current element
struct node *head = NULL;
struct node *current = NULL;

//Inserting Struct
    void insert (int key, int data){
    //create a link between items
    struct node *link = (struct node*) malloc(sizeof(struct node));
    
    link->key = key;
    link->data = data;
    
    //Connected to old first node via pointer
    link->next = head;
    
    //pointer to new first node
    head = link;
    }

//Searching struct given key
struct node* Find(int key) {
    
    //start from the beginning of the list
    struct node* current = head;
    
    //if list is empty
    if(head == NULL) {
        return NULL;
    }
    
    //Step through list
    while(current->key != key) {
        
        //If we reach the end of the list
        if(current->next == NULL) {
            return NULL;
        } else {
            //Next link
            current = current->next;
        }
    }
    
    //If data found, return the current Link
    return current;
}

//Struct to delete a node given a key
struct node* delete(int key) {
    
    //start from the first link
    struct node* current = head;
    struct node* previous = NULL;
    
    //Empty check
    if(head == NULL) {
        return NULL;
    }
    
    //Step through list in search of the key
    while(current->key != key) {
        
        //if it is last node
        if(current->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }
    
    //found a match, update the link
    if(current == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }
    
    return current;
}

//Print the list to the console
void printList() {
    struct node *ptr = head;
    printf("\n[ ");
    while(ptr != NULL) {
        printf("(%d,%d) ",ptr->key,ptr->data);
        ptr = ptr->next;
    }
    
    printf(" ]\n");
}

/*
        S T A C K
*/

//Code translates a linked list into a stack
void Reverse(struct node** head_ref) {
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    
    while (current != NULL) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int length() {
    int length = 0;
    struct node *current;
    
    for(current = head; current != NULL; current = current->next) {
        length++;
    }
    
    return length;
}

void pop(){

    //Empty check
    if(head == NULL) {
        printf("Stack is empty /n");
    }
    //Popping the top value off the Stack
    delete(length());
        }


//Adding a value into the top of the stack
void push(int data){
    int x = length()+1;
    insert(x, data);
}


/*
        Q U E U E
*/

struct node* Fifo() {
    
    //save reference to first link
    struct node *tempLink = head;
    
    //mark next to first link as first
    head = head->next;
    
    //return the deleted link
    return tempLink;
}


int main(int argc, const char * argv[]) {
    //Creating the list
    insert(1, 42);
    insert(2, 1337);
    insert(3, 4311);
    insert(4, 420);
    insert(5, 43110);
    //Printing List
    printList();
    //Deleting item with second key
    delete(2);
    //Printing List
    printList();
    //Searching Time
    Find(3);
    
    
    //Converting the linked list into a stack
    Reverse(&head);
    //Using the pop
    pop();
    printList();
    push(12345);
    printList();
    
    //Converting back to a queue
    Reverse(&head);
    //Removing the first element of the queue
    Fifo();
    return 0;
}

