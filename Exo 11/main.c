#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    float grade;
};

void fill_students_info(struct Student students[], int N) {
    printf("\n==============| Fill Students |=============\n");
    for (int i = 0; i < N; i++) {
        printf("------| Student %d |------\n", i+1);
        do {
            printf("Student Name: ");
            fgets(students[i].name, 50, stdin);
            students[i].name[strlen(students[i].name)-1] = '\0';
        } while (strlen(students[i].name) < 3);
        do {
            printf("Student Grade: ");
            scanf("%f", &students[i].grade);
        } while (students[i].grade < 0 || students[i].grade > 20);
        getchar();
    }
    printf("============================================\n\n");
}

float calc_class_avg(struct Student students[], int N) {
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += students[i].grade;
    }
    return (float) sum / N;
}

struct Student student_lowest_grade(struct Student students[], int N) {
    int min_index = 0;
    for (int i = 1; i < N; i++) {
        if (students[i].grade < students[min_index].grade) {
            min_index = i;
        }
    }
    return students[min_index];
}

struct Student student_highest_grade(struct Student students[], int N) {
    int max_index = 0;
    for (int i = 1; i < N; i++) {
        if (students[i].grade > students[max_index].grade) {
            max_index = i;
        }
    }
    return students[max_index];
}

void display_students_grades(struct Student students[], int N) {
    printf("\n================| Students |================\n");
    for (int i = 0; i < N; i++) {
        printf("%s : %.2f\n", students[i].name, students[i].grade);
    }
}

int main()
{
    int N = 0;
    do {
        printf("Enter The number of students: ");
        scanf("%d", &N);
        getchar();
    } while (N <= 0);

    struct Student students[N];

    fill_students_info(students, N);

    printf("Class Average: %.2f\n", calc_class_avg(students, N));

    struct Student min_student = student_lowest_grade(students, N);
    struct Student max_student = student_highest_grade(students, N);

    printf("Lowest grade is %.2f for student \"%s\"\n", min_student.grade, min_student.name);
    printf("Highest grade is %.2f for student \"%s\"\n", max_student.grade, max_student.name);

    display_students_grades(students, N);

    return 0;
}
