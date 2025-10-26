#include <stdio.h>

int main() {
    int rowA, colA, rowB, colB;
    printf("For multiplication, columns of Matrix A must be equal to rows of Matrix B.\n");

    printf("Enter rows for Matrix A: ");
    scanf("%d", &rowA);
    printf("Enter columns for Matrix A: ");
    scanf("%d", &colA);
    printf("Enter rows for Matrix B: ");
    scanf("%d", &rowB);
    printf("Enter columns for Matrix B: ");
    scanf("%d", &colB);

    while (colA != rowB) {
        printf("\nInvalid size!\n");
        printf("Please re-enter sizes correctly:\n");
        printf("Enter rows for Matrix A: ");
        scanf("%d", &rowA);
        printf("Enter columns for Matrix A: ");
        scanf("%d", &colA);
        printf("Enter rows for Matrix B: ");
        scanf("%d", &rowB);
        printf("Enter columns for Matrix B: ");
        scanf("%d", &colB);
    }

    int matA[rowA][colA], matB[rowB][colB], result[rowA][colB];
    int i, j, k;

    // --- Input Matrix A ---
    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matA[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matB[i][j]);
        }
    }
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            for (k = 0; k < colA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    printf("\nResult\n");

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++)
            printf("%4d ", matA[i][j]);

        if (i == rowA / 2) printf("  x  "); 
        else printf("     ");

        for (j = 0; j < colB; j++)
            printf("%4d ", matB[i][j]);

        if (i == rowA / 2) printf("  =  ");
        else printf("     ");

        for (j = 0; j < colB; j++)
            printf("%4d ", result[i][j]);

        printf("\n");
    }

    return 0;
}
