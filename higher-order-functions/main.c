#pragma GCC diagnostic error "-Wall"
#pragma GCC diagnostic error "-Wdiscarded-qualifiers"
#pragma GCC diagnostic error "-Wincompatible-pointer-types"
#pragma GCC diagnostic error "-Wint-conversion"


#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <inttypes.h>
#include <stdint.h>
#include "io.h"
#include "list.h"



// --- начало решения на Stepik ---

/* Запустить функцию f на каждом элементе списка  */
void list_foreach(const struct list* l, void (f)(int64_t)) {
    if (l != NULL){
        struct list current = *l;
        while (current.next != NULL){
            f(current.value);
            current = *current.next;
        }
        f(current.value);
    }
}


/* Изменить каждый элемент списка с помощью функции f  */
void list_map_mut(struct list* l, int64_t (f) (int64_t)) {
    if (l != NULL){
        while (l->next != NULL){
            l->value = f(l->value);
            l = l->next;
        }
        l->value = f(l->value);
    }
}


/*  Создать новый список, в котором каждый элемент получен из соответствующего
 элемента списка l путём применения функции f */
struct list* list_map( const struct list* l, int64_t (f) (int64_t)) {
    struct list* result = NULL;
    struct list* output = NULL;
    if (l != NULL){
        struct list current = *l;
        while (current.next != NULL){
            struct list* new = node_create(f(current.value));
            if (result != NULL) {
                result->next = new;
                result = result->next;
            }
            if (result == NULL) {
                output = new; 
                result = new;
            }
            current = *current.next;
        }
        struct list* new = node_create(f(current.value));
        result->next = new;
    }
    return output;
}

/* Свернуть список l с помощью функции f. */

int64_t list_fold(const struct list* l, int64_t init, int64_t (f)(int64_t, int64_t)) {
    if (l != NULL){
        struct list current = *l;
        while (current.next != NULL){
            init = f(init, current.value);
            current = *current.next;
        }
        init = f(init, current.value);
    }
    return init;
}

/*  Сгенерировать список длины sz с помощью значения init и функции f
 Результат: init, f(init), f(f(init)), ... */
struct list* list_iterate( int64_t init, size_t sz, int64_t (f)(int64_t) ) {
    struct list* result = NULL;
    struct list* output = NULL;
    for (int64_t i = 0; i < sz; i++){
        if (i != 0 && i !=sz){
            init = f(init);
            struct list* list_new = node_create(init);
            result->next = list_new;
            result = result->next;
        } else if (i == 0 && i !=sz){
            result = node_create(init);
            output = result;
        }
    }
    return output;
}



// --- конец решения на Stepik ---


static int64_t triple( int64_t x ) { return x * 3; }
static int64_t square( int64_t x ) { return x * x; }
static int64_t sum( int64_t x, int64_t y) { return x + y; }

struct list* c(int64_t value, struct list* tail) {
  struct list* l = node_create(value);
  l->next = tail;
  return l;
}


void print_int64_space(int64_t i) { 
    print_int64( i );
    printf(" "); 
}
void list_print(const struct list* l) { 
    list_foreach(l, print_int64_space);
}

int main() {
  typedef struct list list;
  list* l1 = c(1, c(2, c(3, c(9, NULL))));
  list const* l1c = l1;

  list_foreach( l1c, print_int64_space);
  print_newline();

  
  list* l2 = list_map( l1c, triple);
  list_map_mut( l2, square);
  list const* l2c = l2;

  list_foreach( l2c, print_int64_space);
  print_newline();

  print_int64( list_fold( l2c, 0, sum));
  print_newline();

  list* l3 = list_iterate( 7, 10, triple);
  list const* l3c = l3;
  list_foreach( l3c, print_int64_space);
  print_newline();


  list_destroy( l1 );
  list_destroy( l2 );
  list_destroy( l3 );

  return 0;
}

