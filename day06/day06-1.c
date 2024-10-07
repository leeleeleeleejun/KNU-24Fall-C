#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->link = NULL;

    return new_node;
}

struct NODE* last_node()
{
    struct NODE* cur = head;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    return cur;
}

void insert_node_last(struct NODE* new_node)
{
    struct NODE* last = last_node();
    last->link = new_node;

}

void print_nodes() {
    struct NODE* cur = head->link;
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->link;
    }
}

int delete_node(int value) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;

    while (cur != NULL)
    {
        if (cur->data == value) {
            prev->link = cur->link;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
}

int delete_node(int value);

int main() {

    head = (struct  NODE*)malloc(sizeof(struct NODE));
    head->link = NULL;

    insert_node_last(create_node(1));
    insert_node_last(create_node(2));
    insert_node_last(create_node(3));
    insert_node_last(create_node(4));
    insert_node_last(create_node(5));

    print_nodes();

    delete_node(3);

    print_nodes();

    return 0;
}

