//
// Created by Anastasia on 11.12.2021.
//

#ifndef STEPIC_C_COURSE_ARRAY_ARRAY_H
#define STEPIC_C_COURSE_ARRAY_ARRAY_H

/*  ---- structure int[][] ---- */

struct array_array_int {
    struct array_int* data;
    size_t size;
};

/*  --- строки ---  */
struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i );
bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value );

/*  --- get/set ---  */
struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j );
bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value );

/*  --- read/print ---  */
struct array_array_int array_array_int_read();
void array_array_int_print( struct array_array_int array);

/*  --- min/normalize ---  */
struct maybe_int64 array_array_int_min( struct array_array_int array );
void array_array_int_normalize( struct array_array_int array, int64_t m);

void array_array_int_free( struct array_array_int array );

#endif //STEPIC_C_COURSE_ARRAY_ARRAY_H

