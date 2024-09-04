#ifndef __STUDENT_M__
#define __STDUENT_M__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"

enum option_id{
    ADD_STUDENT =1,
    FIND_STUDENT,
    PRINT_STUDENT,
    MODIFY_STUDENT,
    DELETE_STUDENT,
    EXIT_SYSTEM
};

extern bool login_status;
extern void login();
extern void insert_student(linknode_t *head);
extern void find_student(linknode_t *head);
extern void display_student(linknode_t *head);
extern void update_student(linknode_t *head);
extern void delete_student(linknode_t *head);


#endif