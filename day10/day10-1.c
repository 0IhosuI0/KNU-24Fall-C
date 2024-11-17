#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE{
    char name[100];
    int score;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_student(int score, char name[100]){
    struct NODE* new_student = (struct NODE*)malloc(sizeof(struct NODE));
    new_student -> score = score;
    strcpy(new_student -> name, name);
    new_student -> link = NULL;

    return new_student;
}

int Check_Name(char name[100]){
    struct NODE* cur = head -> link;
    while(cur != NULL){
        if(strcmp(cur -> name, name) == 0){
            return -1;
        }
        cur = cur -> link;
    }
    return 0;
}

void insert_node(struct NODE* new_student){
    struct NODE* cur = head;
    struct NODE* next = cur -> link;
    if(Check_Name(new_student -> name) == -1){
        printf("----------------------------\n");
        printf("[WANRING!] 중복된 이름이 있습니다!\n");
        free(new_student);
    }
    else if(Check_Name(new_student -> name) == 0){
        while (next != NULL && next -> score > new_student -> score) {
            cur = cur -> link;
            next = next -> link;
        }
        new_student -> link = next;
        cur -> link = new_student;
    }
}

void print_nodes(){
    struct NODE* cur = head -> link;
    printf("<학생 정보>\n");
    while(cur != NULL){
        printf("%s\t:\t%d\n", cur -> name, cur -> score);
        cur = cur -> link;
    }
}

int delete_node(char name[100]){
    struct NODE* prev = head;
    struct NODE* cur = head -> link;
    while(cur != NULL){
        if(strcmp(cur -> name, name) == 0){
            prev -> link = cur -> link;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur -> link;
    }
    return 0;
}

int main(){
    int choice = 0, score;
    char name[100];
    head = (struct NODE*)malloc(sizeof(struct NODE));
    head -> link = NULL;

    while(choice != 3){
        printf("----------------------------\n");
        print_nodes();
        printf("----------------------------\n");
        printf("1. 학생의 정보를 입력\n");
        printf("2. 학생의 정보를 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &choice);
        
        if (choice == 1){
            printf("학생 이름 : ");
            scanf("%s", name);
            printf("점수 : ");
            scanf("%d", &score);

            insert_node(create_student(score, name));

        }
        else if(choice == 2){
            printf("어떤 학생의 정보를 제거하시겠습니까 : ");
            scanf("%s", name);
            if(delete_node(name) == 1){
                printf("----------------------------\n");
                printf("성공적으로 제거 되었습니다.\n");
            }
            else if(delete_node(name) == 0){
                printf("----------------------------\n");
                printf("[WARNING!] 입력하신 정보가 없습니다!\n");
            }
        }
        else if(choice != 3){
            printf("----------------------------\n");
            printf("[WARNING!] 잘못된 입력입니다!\n");
            getchar();
        }

    }
    printf("----------------------------\n");
    printf("프로그램이 성공적으로 종료되었습니다.\n");
    printf("----------------------------\n");
    return 0;
}