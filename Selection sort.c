#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    int* a;
    int n, min, changenum, helpmax;
    int j1 = 0;
    int j2 = 0;
    srand(time(NULL));
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
    min = a[n - 1];
    clock_t begin = clock();
    for (j1; j1 < n; j1++) {
        for (j2; j2 < n; j2++) {
            if (a[j2] <= min) {
                min = a[j2];
                changenum = j2;
            }
        }
        helpmax = a[j1];
        a[j1] = a[changenum];
        a[changenum] = helpmax;
        min = a[n - 1];
        j2 = j1 + 1;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d\n", n);
    DWORD dwStart = GetTickCount();
    printf("%f", time_spent);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}