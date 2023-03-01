#include <stdio.h>

int max[10][10], allocation[10][10], need[10][10];
int avail[10];
int np, nr;

void readmatrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++) {
        printf("\n P%d", i);
        for (j = 0; j < nr; j++) {
            printf(" %d", matrix[i][j]);
        }
    }
}

void calculate_need() {
    int i, j;
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void banker() {
    int i, j, k = 0, flag;
    int finish[10], safe_seq[10];
    for (i = 0; i < np; i++) {
        finish[i] = 0;
    }
    for (i = 0; i < np; i++) {
        flag = 0;
        if (finish[i] == 0) {
            for (j = 0; j < nr; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                finish[i] = 1;
                safe_seq[k] = i;
                k++;
                for (j = 0; j < nr; j++) {
                    avail[j] += allocation[i][j];
                }
                i = -1;
            }
        }
