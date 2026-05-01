#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* intersection(struct Node* a, struct Node* b) {
    struct Node* pa = a;
    struct Node* pb = b;
    while (pa != pb) {
        pa = pa ? pa->next : b;
        pb = pb ? pb->next : a;
    }
    return pa;
}

void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    struct Node* a = create_node(1);
    a->next = create_node(2);
    a->next->next = create_node(3);
    struct Node* b = create_node(4);
    b->next = a->next;
    printf("List A: "); print_list(a);
    printf("List B: "); print_list(b);
    struct Node* inter = intersection(a, b);
    if (inter) printf("Intersection: %d\n", inter->data);
    else printf("No intersection\n");
    return 0;
}