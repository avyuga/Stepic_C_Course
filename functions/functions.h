#ifndef STEPIC_C_COURSE_FUNCTIONS_H
#define STEPIC_C_COURSE_FUNCTIONS_H

// Мы хотим, чтобы в структуре user хранились ссылки только на строчки из кучи.
typedef struct { char* addr; } string_heap ;

/*  Тип для идентификаторов пользователей
    и его спецификаторы ввода и вывода для printf */
typedef uint64_t uid;
#define PRI_uid PRIu64
#define SCN_uid SCNu64

enum city {C_SARATOV, C_MOSCOW, C_PARIS, C_LOS_ANGELES, C_OTHER};

/*  Массив, где элементам перечисления сопоставляются их текстовые представления */
const char* city_string[] = {
        [C_SARATOV] = "Saratov",
        [C_MOSCOW] = "Moscow",
        [C_PARIS] = "Paris",
        [C_LOS_ANGELES] = "Los Angeles",
        [C_OTHER] = "Other"
};

struct user {
    const uid id;
    const string_heap name;
    enum city city;
};

#endif //STEPIC_C_COURSE_FUNCTIONS_H
