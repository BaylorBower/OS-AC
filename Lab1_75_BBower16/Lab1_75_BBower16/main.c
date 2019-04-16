//
//  main.c
//  Lab1_75_BBower16
//
//  Created by Baylor K. Bower on 3/24/19.
//  Copyright © 2019 Baylor K. Bower. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/*
        ***DOUBLY LINKED LIST***
 */
struct node {
    int data;
    int key;
    
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;//Head will always point to first element
struct node *last = NULL;//Last wiil always poin to the last element
struct node *current = NULL;//Points to the current element

bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;
    
    for(current = head; current != NULL; current = current->next){
        length++;
    }
    
    return length;
}

//Print the entire list
void printList() {
    
    struct node *ptr = head;
    printf("\n[ ");
    //Loop to iterate throughout the entire list
    while(ptr != NULL) {
        printf("(%d,%d) ",ptr->key,ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

//Print the entire list
int createArray() {
    int arraysize = length();
    int array[arraysize];
    int i = 0;
    struct node *ptr = head;
    
    //Loop to iterate throughout the entire list
    while(ptr != NULL) {
        array[i]= ptr->data;
        i++;
        ptr = ptr->next;
    }
    return array[arraysize];
}
 //Print data given key
void findInList(int key) {
    
    struct node *ptr = head;
    //Loop to iterate throughout the entire list
    while(ptr->key != key) {
         ptr = ptr->next;
    }
    if (ptr->key == key) {
        printf("\n (%d) ",ptr->data);
    }else{
        printf("Something went wrong");
    }
}

//Delete element with a certain key
struct node* delete(int key) {
    
    struct node* current = head;
    struct node* previous = NULL;
    
    //Empty Check
    if(head == NULL) {
        return NULL;
    }
    
    
    while(current->key != key) {
        //Loop to iterate thought the list
        if(current->next == NULL) {
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }
    
    //found a match, update the link
    if(current == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        current->prev->next = current->next;
    }
    
    if(current == last) {
        //change last to point to prev link
        last = current->prev;
    } else {
        current->next->prev = current->prev;
    }
    
    return current;
}

void insert(int key, int data) {
    
    //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    
    if(isEmpty()) {
        //make it the last link
        last = link;
    } else {
        //update first prev link
        head->prev = link;
    }
    
    //point it to old first link and new first link
    link->next = head;
    head = link;
}

bool insertAfter(int key, int newKey, int data) {
    //start from the first link
    struct node *current = head;
    
    //if list is empty
    if(head == NULL) {
        return false;
    }
    
    //navigate through list
    while(current->key != key) {
        
        //if it is last node
        if(current->next == NULL) {
            return false;
        } else {
            //move to next link
            current = current->next;
        }
    }
    
    //Links everything together
    struct node *newLink = (struct node*) malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;
    
    if(current == last) {
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }
    newLink->prev = current;
    current->next = newLink;
    return true;
}
/*
        ***CIRCULAR BUFFER
*/

typedef struct {
    uint8_t * const buff;
    int head;
    int tail;
    const int maxLen;

}cBuff;

int BuffPush(cBuff *cBuffer, uint8_t data)
{
    int next;
    next = cBuffer->head + 1;
    
    if (next >= cBuffer->maxLen){
        next = 0;
    }
    //Makes sure the buffer does not exceed maxLen
    if (next == cBuffer->tail){
        return -1;
    }
    cBuffer->buff[cBuffer->head] = data;
    cBuffer->head = next;
    return 0;
}

int buffPop(cBuff *c, uint8_t *data)
{
    int next;
    //Empty Buffer
    if (c->head == c->tail)
        return -1;
    
    next = c->tail + 1;
    
    if(next >= c->maxLen)
        next = 0;
    
    printf("Removed %d from the Buffer \n", *data);
    *data = c->buff[c->tail];
    c->tail = next;
    
    return 0;
}


/*
        ***MAIN***
 */
int main(int argc, const char * argv[]) {
    insert(1, 20);
    insert(2, 420);
    insert(3, 1138);
    insert(4, 1337);
    printList();
    delete(3);
    printList();
    findInList(1);
    
    
    
    
    
    
    
    

    return 0;
    
}
