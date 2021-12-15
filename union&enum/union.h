//
// Created by Anastasia on 15.12.2021.
//

#ifndef STEPIC_C_COURSE_UNION_H
#define STEPIC_C_COURSE_UNION_H

enum either_type { ET_INT, ET_STRING };

struct either_int_string {
    enum either_type type;
    union {
        char* as_string;
        int64_t as_int;
    };
};

struct either_int_string either_from_string(char* s);
struct either_int_string either_from_int(int64_t i);
void either_int_string_destroy(struct either_int_string e);

struct heap_string {
    char* addr;
};

struct heap_string halloc( const char* s );
void heap_string_free( struct heap_string h );


#endif //STEPIC_C_COURSE_UNION_H
