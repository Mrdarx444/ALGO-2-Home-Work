#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;

struct Element {
    int val;
    Element *next;
};

Element *head;

int main()
{
    Element *E1;
    E1 = malloc(sizeof(Element));
    head = E1;
    E1->val = 10;
    E1->next = NULL;

    Element *E2;
    E2 = malloc(sizeof(Element));
    head = E2;
    E2->val = 20;
    E2->next = E1;

    Element *E3;
    E3 = malloc(sizeof(Element));
    E1->next = E3;
    printf("Enter The third Element: ");
    scanf("%d", &E3->val);
    E3->next = NULL;

    Element *E = head;
    printf("Head---->");
    while (E != NULL) {
        printf("[%d]---->", E->val);
        E = E->next;
    }
    printf("NULL\n");

    free(E1);
    free(E2);
    free(E3);

    return 0;
}
