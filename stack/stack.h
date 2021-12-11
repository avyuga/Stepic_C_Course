#ifndef STEPIC_C_COURSE_STACK_H
#define STEPIC_C_COURSE_STACK_H

#include <array.h>

struct stack {
    size_t count;
    struct array_int data;
};

// Количество элементов в стеке
size_t stack_count( const struct stack* s );

struct array_int array_int_create( size_t sz );

// Создаем и деинициализируем стек
struct stack stack_create( size_t size );
void stack_destroy( struct stack* s );

// Стек полный
bool stack_is_full( const struct stack* s);
// Стек пустой
bool stack_is_empty( const struct stack* s);

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value );

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64
stack_pop( struct stack* s );

void stack_print( const struct stack* s );

#endif //STEPIC_C_COURSE_STACK_H
