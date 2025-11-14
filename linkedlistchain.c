#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct
{
    char Name[20];
    int Grades;
} Student;

typedef struct
{
    Student elem[MAXSIZE];
    int length;
} SeqList;

void InitList(SeqList *L)
{
    L->length = 0;
}

void Displaylist(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%s %d\n", L->elem[i].Name, L->elem[i].Grades);
    }
}

int main()
{
    SeqList L;
    InitList(&L);

    Student students[] = {
        {"Tom", 98},
        {"Sam", 96},
        {"Bill", 97},
        {"Alex", 96}};

    for (int i = 0; i < 4; i++)
    {
        L.elem[i] = students[i];
        L.length++;
    }

    printf("Initiallist: \n");
    Displaylist(&L);

    int i, k;

    // Search for "Sam" and insert "Jack" after him
    k = -1;
    for (i = 0; i < L.length; i++) {
        if (strcmp(L.elem[i].Name, "Sam") == 0) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        printf("Student not found\n");
    } else {
        /* Shift elements right to make room at position k+1. Start from
           L.length and move down; writing to L.elem[L.length] is safe
           because MAXSIZE is large enough for this example. */
        for (i = L.length; i > k + 1; i--) {
            L.elem[i] = L.elem[i - 1];
        }

        /* Insert new student */
        strcpy(L.elem[k + 1].Name, "Jack");
        L.elem[k + 1].Grades = 76;
        L.length++;
    }

    printf("\n");
    Displaylist(&L);
    return 0;
}
