#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "union.h"

// Создание экземпляров из строки или из числа
// Всегда передаётся строка, выделенная в куче
struct either_int_string either_from_string(char* s) {
    return (struct either_int_string){.type = ET_STRING, .as_string = s};
}
struct either_int_string either_from_int(int64_t i) {
    return (struct either_int_string){.type = ET_INT, .as_int = i};
}

// очистить память под строку (если строка)
void either_int_string_destroy(struct either_int_string e) {
    free(e.as_string);
}


// конструкция switch используется для ветвления по значению числа,
// например, перечисления.
// Для строк и других типов данных использоваться не может
// Каждая ветка должна завершаться break
void print(struct either_int_string e) {
    switch (e.type) {
        case ET_INT: {
            printf("Int %" PRId64, e.as_int);
            break;
        }
        case ET_STRING: {
            printf("String %s", e.as_string);
            break;
        }
            // Ветка по-умолчанию, если e.type не равен ни ET_INT, ни ET_STRING
        default: {
            break;
        }
    }
}

// скопировать в кучу
struct heap_string halloc( const char* s ){
    size_t counter= 0;
    while (s[counter] != '\0') counter++;
    counter++; // с учетом нуль-терминатора
    struct heap_string result;
    result.addr = malloc(counter*sizeof(char));
    for (size_t i = 0; i < counter; i++) result.addr[i] = s[i];
    return result;
}

// освободить память
void heap_string_free( struct heap_string h ){
    free(h.addr);
}