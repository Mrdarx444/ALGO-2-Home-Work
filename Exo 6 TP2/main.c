#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
typedef Element *Cell;

struct Element {
    int info;
    Cell next;
};

Cell List = NULL;

void InsertHead(Cell *L, int N) {
    Cell E = malloc(sizeof(Element));
    E->info = N;
    E->next = *L;
    if (E==NULL) {
        printf("Error");
        return;
    }
    *L=E;
}

void CreateList() {
    int N;
    do {
        printf("Enter N: ");
        scanf("%d", &N);
        if (N >= 0)
            InsertHead(&List, N);
    } while (N >= 0);
}

void DisplayList(Cell L) {
    if (L == NULL) {
        printf("Empty list\n");
        return;
    }
    Cell E = L;
    while (E != NULL) {
        printf(" [%d] -----", E->info);
        E = E->next;
    }
}

int main()
{
    CreateList();
    DisplayList(List);
    free(List);
    return 0;
}
