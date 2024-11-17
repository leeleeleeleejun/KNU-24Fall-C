#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void insert_student(const char* name, int score) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->next = NULL;

    if (head == NULL || head->score < score) {
        new_node->next = head;
        head = new_node;
        printf("%s(%d) 추가됨.\n", name, score);
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->score >= score) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    printf("%s(%d) 추가됨.\n", name, score);
}

void delete_student(const char* name) {
    if (head == NULL) {
        printf("%s를 삭제할 수 없습니다. (목록이 비어 있음)\n", name);
        return;
    }

    if (strcmp(head->name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("%s 삭제됨.\n", name);
        return;
    }

    Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("%s를 찾을 수 없습니다.\n", name);
    } else {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("%s 삭제됨.\n", name);
    }
}

void print_students() {
    if (head == NULL) {
        printf("학생이 없습니다.\n");
        return;
    }

    printf("전체 학생 목록 :\n");
    Node* current = head;
    while (current != NULL) {
        printf("- %s: %d점\n", current->name, current->score);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("----------------------------\n");
        printf("1. 학생 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("학생 이름: ");
            scanf("%s", name);
            printf("%s의 점수: ", name);
            scanf("%d", &score);
            insert_student(name, score);
            printf("----------------------------\n");
            print_students();
        } else if (choice == 2) {
            printf("삭제할 학생 이름: ");
            scanf("%s", name);
            delete_student(name);
            printf("----------------------------\n");
            print_students();
        } else if (choice == 3) {
            printf("프로그램 종료\n");
            break;
        } else {
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
