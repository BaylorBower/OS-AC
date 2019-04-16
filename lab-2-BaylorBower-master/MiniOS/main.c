//
//  main.c
//  MiniOS
//
//  Created by Aaron David Block on 1/31/19.
//  Copyright © 2019 Austin College. All rights reserved.
//

#include <stdio.h>
#include "MemoryTests.h"
#include "ACMemory.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Starting Tests!\n");
    OS_Memory memory;
    initialize_memory(&memory,16);
    double test = 13.37;
    double test2 = 42.0;
    double test3 = 1138.0;
    
    double* pointer = push_bytes(&memory, &test, sizeof(double));
    double* pointer2 = push_bytes(&memory, &test2, sizeof(double));
    double* pointer3 = push_bytes(&memory, &test3, sizeof(double));
    
    printf("%f\n", *(double*)pointer);
    printf("%f\n", *(double*)pointer2);
    printf("%f\n", *(double*)pointer3);
    
    double* popper = pop_bytes(&memory);
    printf("%f\n", *(double*)popper);
    popper = pop_bytes(&memory);
    printf("%f\n", *(double*)popper);
    
    /* Stack Tests */
    basic_stack_test();
    basic_int_test();
    basic_double_test();
    basic_mixed_test();
    basic_struct_test();
    free_memory(&memory);
    printf("All Tests passed!\n");
    return 0;
}
