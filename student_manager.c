#include "student_manager.h"

bool login_status = false;

void login(){
    char username[30] = {0};
    char password[30] = {0};

    printf("==========Login:===========\n");
    printf("Username:");
    //gets(username);
    fgets(username,sizeof(username),stdin);
    username[strlen(username) - 1] = '\0';

    printf("Password:");
    //gets(password);
    fgets(password,sizeof(password),stdin);
    password[strlen(password) - 1] = '\0';

    if((strcmp(username,"root") == 0) && (strcmp(password,"root") == 0)){
        login_status = true;
        printf("Login successful\n");
    }else{
        login_status = false;
        printf("Username or password wrong\n");
    }
}

void insert_student(linknode_t *head){
    bool student_exist = false;
    s_t student = {0};
    linknode_t *p = NULL;

    printf("==========================\n");
    printf("Enter student info(matric name gender age score):");
    scanf("%d%s%s%d%lf",&(student.id),student.name,student.sex,&(student.age),&(student.score));

    while(getchar() != '\n');

    p = head;
    while(p->next != NULL){
        if(p->next->data.id == student.id){
            student_exist = true;
            printf("Student Id duplicated!\n");
            break;
        }
        p = p->next;
    }

    if(!student_exist){
        insert_tail_linklist(head,student);
        printf("Insert successful\n");
    }
}

void display_student(linknode_t *head){
    linknode_t *p = head;

    printf("========================Student Info============================\n");
    printf("|ID\t|Name\t|Gender\t|Age\t|Score|\n");
    while(p -> next != NULL){
        printf("|%d\t|%s\t|%s\t|%d\t|%.1f\t|\n",p->next->data.id,p->next->data.name,
        p->next->data.sex,p->next->data.age,p->next->data.score);

        p = p -> next;
    }
    printf("========================Student Info============================\n");
}

void find_student(linknode_t *head){
    linknode_t *p = head;
    int id;

    printf("Enter the student id:");
    scanf("%d",&id);

    while(p ->next != NULL){
        if(p->next->data.id == id){
            printf("|ID\t|Name\t|Gender\t|Age\t|Score\t|\n");
            printf("|%d\t|%s\t|%s\t|%d\t|%.1f\t|\n",p->next->data.id,p->next->data.name,
            p->next->data.sex,p->next->data.age,p->next->data.score); 
            return;
        }
        p = p->next;
    }

    if(p->next == NULL){
        printf("=================================\n");
        printf("Not Found\n");
        printf("=================================\n"); 
    }
}

void update_student(linknode_t *head){
    linknode_t *p = head;
    int id;

    printf("Enter the id that you want amend:");
    scanf("%d",&id);

    while(p ->next != NULL){
        if(p->next->data.id == id){
            s_t student_new = {0};
            student_new.id = id;
            printf("Enter student info(Name Sex Age Score):");
            scanf("%s%s%d%lf",student_new.name,student_new.sex,&(student_new.age),&(student_new.score));

            p->next->data = student_new;
            printf("Amend successful\n");
            return;
        }
        p = p->next;
    }

    if(p ->next == NULL){
        printf("=================================\n");
        printf("Incorrect Student Id\n");
        printf("=================================\n");
    }
}

void delete_student(linknode_t *head){
    int ret;
    int id;

    printf("Enter student id that you want delete:");
    scanf("%d",&id);

    ret = delete_data_linklist(head,id);


    if(ret <0){
        printf("=================================\n");
        printf("Delete failed\n");
        printf("=================================\n");
    }
}