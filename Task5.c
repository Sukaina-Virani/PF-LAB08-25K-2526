#include <stdio.h>

int main() {
    int i, j;
    int same;

    int mat[3][3][3] = {
        { {1,2,3}, {0,1,4}, {5,6,0} }, { {8,8,0}, {7,5,3}, {3,5,7} }, { {8,8,0}, {7,5,3}, {3,5,7} }};

    same = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[0][i][j] != mat[1][i][j]) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }
    if (same)
        printf("\nLayer 1 and 2 are same.\n");
    else
        printf("\nLayer 1 and 2 are diff.\n");

    same = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[0][i][j] != mat[2][i][j]) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }
    if (same)
        printf("Layer 1 and 3 are same.\n");
    else
        printf("Layer 1 and 3 are diff.\n");

    same = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[1][i][j] != mat[2][i][j]) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }
    if (same)
        printf("Layer 2 and 3 are same.\n");
    else
        printf("Layer 2 and 3 are diff.\n");

    return 0;
}
