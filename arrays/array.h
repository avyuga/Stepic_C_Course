#ifndef TRY_ARRAY_H
#define TRY_ARRAY_H

#include <stdbool.h>

size_t read_size();
int64_t read_int64();

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

extern const struct maybe_int64 none_int64;
extern const struct maybe_array_int none_array_int;

struct maybe_int64 array_int_get(struct array_int a, size_t i);
struct maybe_int64 some_int64(int64_t i);
struct maybe_array_int some_array_int(struct array_int array);

void array_int_fill( int64_t* array, size_t sz );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
struct array_int array_int_read();
struct maybe_int64 array_int_min( struct array_int array );
void array_int_free( struct array_int* a );
void array_int_normalize( struct array_int array, int64_t m );


#endif //TRY_ARRAY_H
