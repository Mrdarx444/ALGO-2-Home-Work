#include <stdio.h>
#include <stdlib.h>

int T_size = 0, TP_size = 0, TN_size = 0;
float *T, *TP, *TN;

void fill_array() {
    printf("\n===============================\n");
    for (int i = 0; i < T_size; i++) {
        printf("Enter Element %d: ", i+1);
        scanf("%f", &T[i]);
        if (T[i] > 0) {
            TP_size++;
        }if (T[i] < 0) {
            TN_size++;
        }
    }
}

void fill_tp_and_tn() {
    TP = (float *) malloc(TP_size * sizeof(float));
    TN = (float *) malloc(TN_size * sizeof(float));

    int TP_p = 0;
    int TN_p = 0;
    for (int i = 0; i < T_size; i++) {
        if (T[i] > 0) {
            TP[TP_p] = T[i];
            TP_p++;
        } else if (T[i] < 0) {
            TN[TN_p] = T[i];
            TN_p++;
        }
    }

}

void display_array(float *arr, int size) {
    printf("[");
    for (int i=0; i < size; i++) {
        printf("%.2f", arr[i]);
        if (i < size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    printf("Enter Table Size: ");
    do {
        scanf("%d", &T_size);
    } while (T_size <= 0);

    T = (float *) malloc(T_size * sizeof(float));

    fill_array();
    printf("\n===============================\n");
    printf("T = ");
    display_array(T, T_size);

    fill_tp_and_tn();

    printf("TP = ");
    display_array(TP, TP_size);
    printf("TN = ");
    display_array(TN, TN_size);


    return 0;
}
