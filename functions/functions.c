#include <inttypes.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


/* Сортировать массив пользователей по полю uid по возрастанию */
int int64_comparer( const uid* x, const uid* y ) {
    if (*x > *y) return 1;
    if (*x < *y) return -1;
    return 0;
}
int int64_void_comparer(const void* x, const void* y ) {
    return int64_comparer(&(((struct user*)x)->id), &(((struct user*)y)->id));
}

void users_sort_uid(struct user users[], size_t sz) {
    qsort(users, sz, sizeof(struct user), int64_void_comparer);
}

/* Сортировать массив пользователей по полю name */
/* Порядок строк лексикографический; можно использовать компаратор
   строк -- стандартную функцию strcmp */
int string_void_comparer(const void* x, const void* y){
    string_heap x_name = ((struct user*)x)->name;
    string_heap y_name = ((struct user*)y)->name;
    return strcmp(x_name.addr, y_name.addr);
}
void users_sort_name(struct user users[], size_t sz) {
    qsort(users, sz, sizeof(struct user), string_void_comparer);
}

/* Сортировать массив по _текстовому представлению_ города */
int city_comparer(const struct user* user1, const struct user* user2){
    const char* city_name1 = city_string[user1->city];
    const char* city_name2 = city_string[user2->city];
    return strcmp(city_name1, city_name2);
}

int city_void_comparer(const void* x, const void* y){
    return city_comparer((const struct user*)x, (const struct user*)y);
}

void users_sort_city(struct user users[], size_t sz) {
    qsort(users, sz, sizeof(struct user), city_void_comparer);
}
