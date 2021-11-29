//
// Created by Anastasia on 18.10.2021.
//

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "array.h"

/*-----structures----*/
struct maybe_int64 {
    int64_t value;
    bool valid;
};

struct array_int{
    int64_t* data;
    size_t size;
};

struct maybe_array_int {
    struct array_int value;
    bool valid;
};


size_t read_size() {
    size_t sz = 0;
    scanf("%zu", &sz);
    return sz;
}
int64_t read_int64(){
    int64_t num;
    scanf("%" SCNd64, &num);
    return num;
}


struct maybe_int64 some_int64(int64_t i) {
    return (struct maybe_int64) { i, true };
}

struct maybe_array_int some_array_int(struct array_int array) {
    return (struct maybe_array_int) { array, true };
}

void array_int_fill( int64_t* array, size_t sz ) {
    for( size_t i = 0; i < sz; i = i + 1 ) {
        *(array+i) = read_int64();
    }
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) {
    if (a.size < i){
        return (struct maybe_int64) {false};
    } else return (struct maybe_int64){*(a.data + i), true};
}

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) {
    if (a.size < i){
        return false;
    } else {
        *(a.data + i) = value;
        return true;
    }
}

void array_int_print( struct array_int array ) {
    for (size_t i = 0; i < array.size; i = i + 1) {
        printf("%" PRId64 " " , array_int_get(array, i).value);
    }
}

struct array_int array_int_read() {
    const size_t size = read_size();
    if (size > 0) {
        int64_t* array = malloc( sizeof(int64_t) * size);
        array_int_fill( array, size );
        return (struct array_int) { .data = array, .size = size };
    }
    else return (struct array_int) {0};
}

struct maybe_int64 array_int_min( struct array_int array ) {
    if (array.size > 0) {
        int64_t min = *(array.data);
        for (size_t i = 0; i < array.size; i++) {
            if (*(array.data + i) < min) {
                min = *(array.data + i);
            }
        }
        return (struct maybe_int64){min, true};
    } else {
        return (struct maybe_int64){0, false};
    }
}

void array_int_free( struct array_int a ) {
    if ( a.size > 0 ) {
        free(a.data);
        a.size = 0;
    }
}

void array_int_normalize( struct array_int array, int64_t m ) {
    for (size_t i = 0; i < array.size; i = i + 1) {
        array.data[i] = array.data[i] - m;
    }
}