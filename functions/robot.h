#ifndef STEPIC_C_COURSE_ROBOT_H
#define STEPIC_C_COURSE_ROBOT_H

enum move_dir { MD_UP, MD_RIGHT, MD_DOWN, MD_LEFT, MD_NONE };

// Определите тип обработчика событий move_callback с помощью typedef
typedef void (*move_callback)(enum move_dir dir);

struct callback_list {
    move_callback callback;
    struct callback_list* next;
};

// Робот и его callback'и
// callback'ов может быть неограниченное количество
struct robot {
    const char* name;
    struct callback_list* callbacks;
};

void register_callback(struct robot* robot, move_callback new_cb);
void unregister_all_callbacks(struct robot* robot);
void move(struct robot* robot, enum move_dir dir);

#endif //STEPIC_C_COURSE_ROBOT_H
