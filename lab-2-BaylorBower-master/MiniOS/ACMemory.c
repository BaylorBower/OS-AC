//
//  Memory420.c
//  Lab02
//
//  Created by Aaron David Block on 1/28/19.
//  Copyright © 2019 Aaron David Block. All rights reserved.
//

#include "ACMemory.h"
#include <assert.h>

#include <stdio.h>

const size_t sizet_size = sizeof(size_t);
const size_t overhead_size = sizeof(void*) + sizet_size;

int initialize_memory(OS_Memory* memory, size_t stack_size){
    memory->size_of_stack = stack_size;
    memory->start_of_stack = malloc(stack_size*overhead_size+overhead_size);
    memory->data = (void*)malloc(sizeof(void*));
    memory->data = &memory->size_of_stack;
    memory->stack_pointer = (void*)malloc(sizeof(void*));
    memory->stack_pointer = &memory->start_of_stack+overhead_size;
    
    return 1;
}


/* frees the memory allocated */
void free_memory(OS_Memory* memory);


/* Pushes the data in bytes onto the stack and returns a pointer to the data's location
 * returns 0 if there is a failure.
 */
void* push_bytes(OS_Memory* memory, void* data, size_t size){
    
    byte databytes[overhead_size]= "";
    byte* ptr = (char*)data;
    *ptr = *(char*)data;
    
    int partitions = 1;
    if(size > overhead_size){
        partitions = (int)(size/overhead_size);
        if(size%overhead_size != 0){
            partitions++;
        }
    }
    
    for(int i = 0; i < size;i++){
        databytes[i] = (byte)ptr[i];
    }
    
    void* pointer = memory->stack_pointer;
    
    printf("%s\n", ptr);
    
    for (int i = 0; i < size; i++) {
        *(char*)pointer = ptr[i];
        pointer++;
    }
    
    pointer = memory->stack_pointer;
    memory->stack_pointer = memory->stack_pointer +(partitions*overhead_size);
    
    return pointer;
}



/* Returns a pointer to the top element on the stack, 0 if there is a failure */

void* get_bytes(OS_Memory* memory){
    memory->data --;
    int x = overhead_size * (int)*(char*)memory->data;
    void* ptr = memory->stack_pointer;
    ptr -= x;
    if (*(char*)memory->data == (char)0) {
        memory->data++;
        return 0;
    }
    memory->data++;
    return ptr;
}


/* Pops off top value from stack.
 * Returns pointer to the popped element, 0 if there is an error.
 * While Pointer is *removed* from the stack, it still lives in memory for a short time. Therefore, if you want to use this data you should immediatly copy it to a more persistant data location since the next push will destroy the data.
 */
void* pop_bytes(OS_Memory* memory){
    memory->data --;
    int x = overhead_size * (int)*(char*)memory->data;
    memory -= x;
    void* ptr = memory->stack_pointer;
    ptr -= x;
    if (*(char*)memory->data == (char)0) {
        memory->data++;
        memory->stack_pointer = &memory->start_of_stack+overhead_size;
        return 0;
    }
    
    return memory->stack_pointer;
}





