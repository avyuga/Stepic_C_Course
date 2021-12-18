#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "maybe_int.h"
#include "io.h"

//#error Вставьте часть решения https://stepik.org/lesson/408350/step/8 содержащую нужные функции и исключая read_int64, maybe_int64_print и определение struct list.

/*
 Список нужных определений:
*/
struct list* node_create( int64_t value ) {
    struct list* result = (struct list*)malloc(sizeof(struct list));
    (*result).value = value;
    (*result).next = NULL;
    return result;
}

void list_destroy( struct list* list ) {
    struct list* last = list;
    do {
        struct list* next = last->next;
        free(last);
        last = next;
    } while (last->next != NULL);
    free(last->next);
    free(last);
}

void list_add_front( struct list** old, int64_t value ) {
    struct list* new_element = node_create(value);
    (*new_element).next = *old;
    *old = new_element;
}

struct list* list_last( struct list* list ) {
    struct list* address = NULL;
    if (list != NULL){
        struct list current = *list;
        while (current.next != NULL){
            address = current.next;
            current = *current.next;
        }
    }
    return address;
}

void list_add_back( struct list** old, int64_t value ) {
    if (*old != NULL) {
        struct list* last = list_last(*old);
        struct list* new = node_create(value);
        last->next = new;
    } else {
        list_add_front(old, value);
    }
}

size_t list_length(const struct list* list) {
    size_t counter = 0;
    if (list != NULL){
        struct list current = *list;
        while (current.next != NULL){
            counter += 1;
            current = *current.next;
        }
        counter += 1;
    }
    return counter;
}

//  struct list* list_node_at( struct list* list, size_t idx ){
//     size_t counter = 0;
//     struct list* current = NULL;
//     if (list != NULL){
//         current = list;
//         while (current->next != NULL){
//             current = current->next;
//             counter += 1;
//             if (counter == idx) break;
//         }
//     }
//     return current->next;
//  }
 struct maybe_int64 list_at(struct list* list, size_t idx);

struct list* list_reverse( const struct list* list ) {
    if (list == NULL){
        return NULL;
    }
    struct list* reversed = (struct list*)malloc(sizeof(struct list));
    int64_t counter = 0;
    while (list != NULL){
        if (counter == 0){
            reversed->value = list->value;
            reversed->next = NULL;
        } else {
            list_add_front(&reversed, list->value);
        }
        if (list->next != NULL){
            list = list->next;
        } else break;
        counter++;
    }
    return reversed;
}



