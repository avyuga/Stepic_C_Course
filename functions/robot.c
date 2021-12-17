#include <malloc.h>
#include <inttypes.h>
#include "robot.h"

// Добавить callback к роботу, чтобы он вызывался при движении
// В callback будет передаваться направление движения
//struct list* list_last( struct list* list ) {
//    struct list* address = NULL;
//    if (list != NULL){
//        struct list current = *list;
//        while (current.next != NULL){
//            address = current.next;
//            current = *current.next;
//        }
//    }
//    return address;
//}
//void list_add_back( struct list** old, int64_t value ) {
//    if (*old != NULL) {
//        struct list* last = list_last(*old);
//        struct list* new = node_create(value);
//        last->next = new;
//    } else {
//        list_add_front(old, value);
//    }
//}
void register_callback(struct robot* robot, move_callback new_cb) {
    struct callback_list* new_callback = malloc(sizeof(struct callback_list));
    new_callback->next = NULL;
    new_callback->callback = new_cb;
    if (robot->callbacks != NULL){
        struct callback_list* list = robot->callbacks;
        while (list->next != NULL) {
            list = list->next;
        }
        list -> next = new_callback;
    } else robot->callbacks = new_callback;

}

// Отменить все подписки на события.
// Это нужно чтобы освободить зарезервированные ресурсы
// например, выделенную в куче память
void unregister_all_callbacks(struct robot* robot) {
    struct callback_list* last = robot->callbacks;
    do{
        struct callback_list* next = last->next;
        free(last);
        last = next;
    } while ((last -> next != NULL));
    free(last);
}

// Вызывается когда робот движется
// Эта функция должна вызвать все обработчики событий
void move(struct robot* robot, enum move_dir dir) {
    struct callback_list* callbacks = robot->callbacks;
    while(callbacks != NULL){
        callbacks->callback(dir);
        callbacks = callbacks->next;
    }
}