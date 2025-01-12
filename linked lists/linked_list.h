//
// Created by Anastasia on 29.11.2021.
//

#ifndef TRY_LINKED_LIST_H
#define TRY_LINKED_LIST_H

struct list {
    int64_t value;
    struct list* next;
};

struct list* node_create( int64_t value );
void list_add_front( struct list** old, int64_t value );
size_t list_length(const struct list* list);
void list_destroy( struct list* list );
struct list* list_last( struct list* list );
void list_add_back( struct list** old, int64_t value );
int64_t list_sum(const struct list* list);
struct maybe_int64 list_at( const struct list* list, size_t idx );
struct list* list_reverse( const struct list* list );
struct maybe_int64 maybe_read_int64();
struct list* list_read();
void list_print(struct list* list);

#endif //TRY_LINKED_LIST_H
