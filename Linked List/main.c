#include <stdio.h>
#include <stdlib.h>

int A, B, C, *P1, *P2;

void display_data() {
    printf("A=%d | B=%d | C=%d | &A=%p | &B=%p | &C=%p | P1=%p | P2=%p | *P1=%d | *P2=%d\n", A, B, C, &A, &B, &C, P1, P2, (*P1), (*P2));
}

int main()
{
    A=1;
    B=2;
    C=3;
    P1=&A;
    P2=&B;
    display_data();
    P2=&C;
    display_data();
    *P1=*P2;
    display_data();
    (*P2)++;
    display_data();
    P1=P2;
    display_data();
    P2=&B;
    display_data();
    (*P2)=(*P1)-2 * (*P2);
    display_data();
    (*P2)--;
    display_data();
    C = (P2 == &C);
    display_data();
    *P2= *P1 + A;
    display_data();
    return 0;
}
