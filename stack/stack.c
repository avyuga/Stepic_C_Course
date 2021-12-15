#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include "array.h"


struct array_int array_int_create( size_t sz ) {
    return (struct array_int) { .data = malloc( sizeof( int64_t ) * sz ), .size = sz };
}

// Количество элементов в стеке
size_t stack_count( const struct stack* s ){
    return s->count;
}

// Создаем и деинициализируем стек
struct stack stack_create( size_t size ){
    return (struct stack) {.count = 0, .data = array_int_create(size)};
}

void stack_destroy( struct stack* s ){
    array_int_free(&(s->data));
    free(s);
}

// Стек полный
bool stack_is_full( const struct stack* s){
    return (s->count == (s->data).size);
}
// Стек пустой
bool stack_is_empty( const struct stack* s){
    return (s->count == 0);
}

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value ) {
    if (s->count >= s->data.size) return false;
    struct array_int res = array_int_create(s->data.size);
    *(res.data) = value;
    for (size_t i = 0; i < s->count; i++){
        res.data[i+1] = *((s->data).data + i);
    }
    array_int_free(&(s->data));
    s->data = res;
    s->count++;
    return true;
}

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64 stack_pop( struct stack* s ){
    if (stack_is_empty(s)) return none_int64;
    struct maybe_int64 result = some_int64(*(s->data.data));
    struct array_int temp = array_int_create(s->data.size);
    for (size_t i =0; i<s->count; i++){
        *(temp.data+i) = *(s->data.data+i+1);
    }
    array_int_free(&(s->data));
    s->data = temp;
    s->count--;
    return result;
}

void stack_print( const struct stack* s ) {
    for (size_t i = 0; i < stack_count(s); i = i + 1 ) {
        printf("%" PRId64, array_int_get(s->data, i).value );
        printf(" ");
    }
}