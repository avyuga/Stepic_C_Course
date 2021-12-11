#include <inttypes.h>
#include <stdio.h>
#include "arrays/array.h"
#include "arrays/array_array.h"
#include "linked lists/linked_list.h"
#include "stack/stack.h"

int main(){
    struct stack stack = {.0, array_int_create(5)};
    printf("%" PRId64 "\n", array_int_get(stack.data, 0).value);
    struct maybe_int64 mb = stack_pop(&stack);
    printf("%" PRId64, mb.value);
    return 0;
}
