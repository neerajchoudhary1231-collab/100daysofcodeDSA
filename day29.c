#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

struct Term* create_term(int coeff, int exp) {
    struct Term* t = (struct Term*)malloc(sizeof(struct Term));
    t->coeff = coeff;
    t->exp = exp;
    t->next = NULL;
    return t;
}

void print_polynomial(struct Term* head) {
    while (head != NULL) {
        if (head->coeff != 0) {
            printf("%dx^%d", head->coeff, head->exp);
            if (head->next != NULL && head->next->coeff > 0) printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    struct Term* poly = create_term(3, 2);
    poly->next = create_term(2, 1);
    poly->next->next = create_term(1, 0);
    printf("Polynomial: ");
    print_polynomial(poly);
    return 0;
}