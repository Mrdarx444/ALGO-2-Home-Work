#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_valid(int number, int base) {

    while (number > 0) {
        int digit = number % 10;
        if (digit >= base) {
            return 0;
        }
        number /= 10;
    }

    return 1;
}

int BaseTo10(int N, int x) {
    int decimal = 0;
    int wheight = 1;

    while (N > 0) {
        int digit = N % 10;
        decimal += digit * wheight;
        wheight *= x;
        N /= 10;
    }
    return decimal;
}

int Base10ToY(int x, int y) {
    int base_y_number = 0;
    int wheight = 1;

    while (x > 0) {
        int digit = (x%y);
        base_y_number += digit * wheight;
        x /= y;
        wheight *= 10;
    }

    return base_y_number;
}

int ConvertBase(int number, int from_base, int to_base) {
    if (from_base == to_base) {
        return number;
    }
    return Base10ToY(BaseTo10(from_base, number), to_base);
}

void main_menu() {
    while (1) {
        int choice;
        do {
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
        } while (choice <= 0 || choice > 4);

        switch (choice) {
            case 1:
                int base, N;
                do {
                    printf("\nEnter The base (N>1): ");
                    scanf("%d", &base);
                } while (base <= 1);
                do {
                    printf("\nEnter The number: ");
                    scanf("%d", &N);
                } while (!is_valid(N, base));

                printf("(%d)_{%d} = (%d)_{10}", N, base, BaseTo10(N, base));
                break;


            case 2:
                int base_y, decimal;
                printf("\nEnter The Decimal number: ");
                scanf("%d", &decimal);
                do {
                    printf("\nEnter The Convertion base (Y>1): ");
                    scanf("%d", &base_y);
                } while (base_y <= 1);
                printf("(%d)_{10} = (%d)_{%d}", decimal, Base10ToY(decimal, base_y), base_y);
                break;
            case 3:
                int number, og_base, to_base;
                do {
                    printf("\nEnter The Original Base (X>1): ");
                    scanf("%d", &og_base);
                } while (og_base <= 1);
                do {
                    printf("\nEnter The number: ");
                    scanf("%d", &number);
                } while (!is_valid(number, og_base));
                do {
                    printf("\nEnter The Convertion Base (Y>1): ");
                    scanf("%d", &to_base);
                } while (to_base <= 1);
                printf("(%d)_{%d} = (%d)_{%d}", number, og_base, ConvertBase(number, og_base, to_base), to_base);
                break;
            default:
                break;
        }
        printf("\n==========================================\n");
        if (choice == 4) {
            printf("\nGoodbye!\n");
            break;
        }
    }
}

int main()
{
    printf("\n===============| Welcome |================\n");
    printf("1) Convert Base N to Decimal.\n");
    printf("2) Convert Decimal to Base N.\n");
    printf("3) Convert BaseX to BaseY.\n");
    printf("4) Exit.\n");
    printf("==========================================\n");

    main_menu();

    return 0;
}
// Boualleg Kaissar
