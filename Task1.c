#include <stdio.h>

int main() {
    float arr[3][3], cofactor[3][3], inverse[3][3];
    float det = 0;
    int i,j;
    
    printf("Enter elements for matrix:\n");

    for(i=0; i<3; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            scanf("%f", &arr[i][j]);
        }
    }
    printf("Matrix:\n ");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
        {
            printf("%.2f   ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     printf("Transpose:\n");
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%.2f   ", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Determinant:\n");
    // Formula: a(ei - fh) - b(di - fg) + c(dh - eg)

    det = arr[0][0]*(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) - arr[0][1]*(arr[1][0]*arr[2][2] - arr[1][2]*arr[2][0]) + arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);

    printf("%f ",det);
    printf("\n");
    printf("\nCofactor:\n");
    cofactor[0][0] =  (arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]);
    cofactor[0][1] = -(arr[1][0]*arr[2][2] - arr[1][2]*arr[2][0]);
    cofactor[0][2] =  (arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);
    cofactor[1][0] = -(arr[0][1]*arr[2][2] - arr[0][2]*arr[2][1]);
    cofactor[1][1] =  (arr[0][0]*arr[2][2] - arr[0][2]*arr[2][0]);
    cofactor[1][2] = -(arr[0][0]*arr[2][1] - arr[0][1]*arr[2][0]);
    cofactor[2][0] =  (arr[0][1]*arr[1][2] - arr[0][2]*arr[1][1]);
    cofactor[2][1] = -(arr[0][0]*arr[1][2] - arr[0][2]*arr[1][0]);
    cofactor[2][2] =  (arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0]);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%.2f   ", cofactor[i][j]);
        }
        printf("\n");
    }
     printf("\nAdjoint:\n");
     //adjoint is transpose of cofactor.
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%.2f   ",cofactor[j][i]);
        }
        printf("\n");
    }
    if (det != 0) {
        printf("\nInverse:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inverse[i][j] = cofactor[j][i] / det;
                printf("%.2f   ", inverse[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nErorr!! determinant is 0 \n");
    }
    return 0;
}
