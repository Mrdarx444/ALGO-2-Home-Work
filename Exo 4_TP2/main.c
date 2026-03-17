#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
typedef Element* List;

struct Element {
    int val;
    Element *next;
};

int main()
{
    Element E1, E2, E3;
    E1.val = 10;
    E1.next = NULL;

    E2.val = 20;
    E2.next = &E1;

    printf("Enter Element 3: ");
    scanf("%d", &E3.val);
    return 0;
}
