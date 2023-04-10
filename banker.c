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
    }
    flag = 0;
    for (i = 0; i < np; i++) {
        if (finish[i] == 0) {
            printf("\nThe system is in deadlock\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nThe system is in safe state! \nSafe sequence is ==>");
        for (i = 0; i < np; i++) {
            printf(" P%d", safe_seq[i]);
        }
    }
}

int main() {
    int j;
    printf("\nEnter number of processes: ");
    scanf("%d", &np);
    printf("\nEnter number of resources: ");
    scanf("%d", &nr);
    printf("\nEnter initial allocation matrix:\n");
    readmatrix(allocation);
    printf("\nEnter max requirement matrix:\n");
    readmatrix(max);
    printf("\nEnter available resources:\n");
    for (j = 0; j < nr; j++) {
        scanf("%d", &avail[j]);
    }
    printf("\n***** Entered data is *****\n\n");
    printf("Initial allocation:\n");

    display_matrix(allocation);
    printf("\n\nMaximum requirement:\n");
    display_matrix(max);
    printf("\n\nAvailable resources:\n");
    for (j = 0; j < nr; j++) {
        printf(" %d", avail[j]);
    }
    printf("\n\nNeed:\n");
    calculate_need();
    display_matrix(need);
    printf("\n\n");
    banker();
    printf("\n\n\n\n");
	return 0;
	}
