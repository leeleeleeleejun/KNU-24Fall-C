#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 고객 등급 열거형 정의
typedef enum {
    GOLD = 1,
    SILVER,
    BRONZE
} Rank;

// 고객 구조체 정의
typedef struct Customer {
    char* customerName;
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

// 리스트의 헤드와 테일 정의
Customer* head = NULL;
Customer* tail = NULL;

// 새로운 고객 생성
Customer* create_customer(const char* name, Rank rank, int order_amount, int point) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    new_customer->customerName = strdup(name); // 문자열 복사
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;
    return new_customer;
}

// 고객 삽입 (우선 관리 순위에 따라 정렬)
void insert_customer(const char* name, Rank rank, int order_amount, int point) {
    Customer* new_customer = create_customer(name, rank, order_amount, point);

    // 리스트가 비어있는 경우
    if (head == NULL) {
        head = tail = new_customer;
        printf("%s 추가됨.\n", name);
        return;
    }

    // 삽입할 위치를 찾음 (우선순위: 등급 → 주문량 → 포인트)
    Customer* current = head;
    while (current != NULL) {
        if (current->rank > rank ||
           (current->rank == rank && current->order_amount < order_amount) ||
           (current->rank == rank && current->order_amount == order_amount && current->point < point)) {
            break;
        }
        current = current->next;
    }

    // 삽입 위치가 리스트의 맨 앞
    if (current == head) {
        new_customer->next = head;
        head->prev = new_customer;
        head = new_customer;
    }
    // 삽입 위치가 리스트의 맨 뒤
    else if (current == NULL) {
        tail->next = new_customer;
        new_customer->prev = tail;
        tail = new_customer;
    }
    // 삽입 위치가 리스트의 중간
    else {
        new_customer->next = current;
        new_customer->prev = current->prev;
        current->prev->next = new_customer;
        current->prev = new_customer;
    }

    printf("%s 추가됨.\n", name);
}

// 고객 삭제
void delete_customer(const char* name) {
    Customer* current = head;

    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            // 리스트에서 노드 제거
            if (current == head) {
                head = current->next;
                if (head) head->prev = NULL;
            } else {
                current->prev->next = current->next;
            }

            if (current == tail) {
                tail = current->prev;
                if (tail) tail->next = NULL;
            } else {
                current->next->prev = current->prev;
            }

            free(current->customerName);
            free(current);
            printf("%s 삭제됨.\n", name);
            return;
        }
        current = current->next;
    }
    printf("%s를 찾을 수 없습니다.\n", name);
}

// 고객 수정
void update_customer(const char* name, Rank rank, int order_amount, int point) {
    delete_customer(name);
    insert_customer(name, rank, order_amount, point);
    printf("%s 수정 완료.\n", name);
}

// 전체 리스트 출력
void print_customers() {
    if (head == NULL) {
        printf("고객이 없습니다.\n");
        return;
    }

    printf("전체 고객 목록 (우선 관리 순위):\n");
    Customer* current = head;
    while (current != NULL) {
        printf("- %s: 등급 %d, 주문량 %d, 포인트 %d\n",
               current->customerName, current->rank, current->order_amount, current->point);
        current = current->next;
    }
}

// 메인 함수
int main() {
    int choice;
    char name[50];
    int rank, order_amount, point;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 고객 리스트 출력\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("고객 이름: ");
            scanf("%s", name);
            printf("고객 등급 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf("%d", &rank);
            printf("주문량: ");
            scanf("%d", &order_amount);
            printf("포인트: ");
            scanf("%d", &point);
            insert_customer(name, rank, order_amount, point);
        } else if (choice == 2) {
            printf("삭제할 고객 이름: ");
            scanf("%s", name);
            delete_customer(name);
        } else if (choice == 3) {
            printf("수정할 고객 이름: ");
            scanf("%s", name);
            printf("고객 등급 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf("%d", &rank);
            printf("주문량: ");
            scanf("%d", &order_amount);
            printf("포인트: ");
            scanf("%d", &point);
            update_customer(name, rank, order_amount, point);
        } else if (choice == 4) {
            print_customers();
        } else if (choice == 5) {
            printf("프로그램 종료.\n");
            break;
        } else {
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}