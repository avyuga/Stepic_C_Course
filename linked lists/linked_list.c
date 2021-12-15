#include <malloc.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"
#include "../arrays/array.h"

struct list {
    int64_t value;
    struct list* next;
};

struct list* node_create( int64_t value ) {
    struct list* result = (struct list*)malloc(sizeof(struct list));
    (*result).value = value;
    (*result).next = NULL;
    return result;
}

void list_add_front( struct list** old, int64_t value ) {
    struct list* new_element = node_create(value);
    (*new_element).next = *old;
    *old = new_element;
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

int64_t list_sum(const struct list* list) {
    int64_t sum = 0;
    if (list != NULL){
        struct list current = *list;
        while (current.next != NULL){
            sum += current.value;
            current = *current.next;
        }
        sum += current.value;
    }
    return sum;
}

struct maybe_int64 list_at( const struct list* list, size_t idx ) {
    int64_t length = list_length(list);
    if (idx < 0 || idx > length || list == NULL){
        return none_int64;
    }
    struct list current = *list;
    while (idx != 0){
        idx -= 1;
        current = *current.next;
    }
    return some_int64(current.value);
}

// создать перевернутую копию списка
void list_add_front( struct list** old, int64_t value );

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
struct maybe_int64 maybe_read_int64() {
    int64_t x;
    int64_t i = scanf("%" SCNd64, &x);
    if (x == EOF || i < 0){
        return none_int64;
    } else{
        return some_int64(x);
    }
}

struct list* list_read() {
    struct list* list = NULL;
    struct list* first = NULL;
    struct maybe_int64 last;
    while (true){
        last = maybe_read_int64();
        if (last.valid) {
            if (list != NULL) {
                list->next = node_create(last.value);
                list = list->next;
            } else {
                list = node_create(last.value);
                first = list;
            }
        } else break;
    }
    free(&last);
    return first;
}


void list_print(struct list* list){
    struct list *p;
    p = list;
    do {
        printf("%" PRId64 " ", p->value); // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != NULL);
    printf("\n");
}