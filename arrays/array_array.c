#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "array.h"
#include "array_array.h"

/*  --- строки ---  */

struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i ) {
    if ( 0 <= i && i < a.size ) {
        return some_array_int(*(a.data + i));
    }
    else {
        return none_array_int;
    }
}

bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value ) {
    if (0 <= i && i < a.size) {
        *(a.data + i) = value;
        return true;
    }
    else { return false; }
}

/*  --- get/set ---  */

struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j ) {
    if ((0 <= i && i < a.size) && (0 <= j && j < (a.data+i)->size)) {
        int64_t value = *((a.data+i)->data + j);
        return (struct maybe_int64) {value, true};
    } else return (struct maybe_int64){0};
}

bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value ) {
    if ((0 <= i && i < a.size) && (0 <= j && j < (a.data+i)->size)){
        *((a.data+i)->data + j) = value;
        return true;
    } else return false;
}

/*  --- read/print ---  */
struct array_array_int array_array_int_read() {
    size_t rows = read_size();
    if (rows > 0){
        struct array_array_int a;
        a.data = malloc(rows*sizeof(struct array_int));
        a.size = rows;
        if (rows > 0) {
            for (size_t i = 0; i < rows; i++) {
                struct array_int line = array_int_read();
                array_array_int_set_row(a, i, line);
            }
        }
        return a;
    }
    struct array_array_int res = {NULL, 0};
    return res;
}

void array_array_int_print( struct array_array_int array) {
    for (size_t i = 0; i < array.size; i++){
        if ((array.data + i)->size != 0) {
            array_int_print(*(array.data + i));
        }
        printf("%s", "\n");
    }
}

/*  --- min/normalize ---  */

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min( struct array_array_int array ) {
    if (array.size > 0){
        struct maybe_int64 min = array_array_int_get(array, 0, 0);
        for (size_t i = 0; i < array.size; i = i + 1) {
            const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
            if (cur_row.valid) {
                for (size_t j = 0; j < cur_row.value.size; j++){
                    if (*(cur_row.value.data + j) < min.value){
                        min = array_array_int_get(array, i, j);
                    }
                }
            }
        }
        return min;
    }
    return none_int64;
}

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize( struct array_array_int array, int64_t m) {
    for (size_t i = 0; i < array.size; i = i + 1) {
        const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
        if (cur_row.valid) {
            array_int_normalize(cur_row.value, m);
        }
    }
}

void array_array_int_free( struct array_array_int array ) {
    for (size_t i = 0; i < array.size; i++){
        array_int_free(*(array.data + i));
    }
    free(array.data);
}
