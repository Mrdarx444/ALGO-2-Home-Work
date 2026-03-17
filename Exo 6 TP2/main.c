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
    E->next = NULL;
    if (E==NULL) {
        printf("Error");
        return;
    }
    *L=E;
}

void InsertTail(Cell *L, int N) {
    Cell E = *L;
    if (E == NULL) {
        InsertHead(L, N);
        return;
    } else {
        Cell tail = malloc(sizeof(Element));
        tail->info = N;
        tail->next = NULL;
        while (E->next != NULL) {
            E = E->next;
        }
        E->next = tail;
    }
}

void CreateList() {
    int N;
    do {
        printf("Enter N: ");
        scanf("%d", &N);
        if (N >= 0)
            InsertTail(&List, N);
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
