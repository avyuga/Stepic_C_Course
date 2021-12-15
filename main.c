#include <inttypes.h>
#include <stdio.h>
#include "arrays/array.h"
#include "arrays/array_array.h"
#include "linked lists/linked_list.h"
#include "stack/stack.h"

int main(){

//    struct stack stack = stack_create(5);
////    stack_push(&stack, 1);
////    stack_push(&stack, 2);
////    stack_push(&stack, 3);
////    stack_push(&stack, 4);
////    stack_push(&stack, 5);
//    stack_push(&stack, 6);
//    stack_print(&stack);
//    struct maybe_int64 mb = stack_pop(&stack);
//    printf("\n%" PRId64 "\n", mb.value);
//    stack_print(&stack);

    struct list* list = list_read();
    list_print(list);
    return 0;
}
