#include <stdio.h>

int main()
{
    int a[3][3][3] = {
        {{5, 12, 8}, {3, 17, 10}, {9, 14, 2}},
        {{7, 1, 16}, {11, 4, 19}, {6, 13, 15}},
        {{18, 9, 5}, {2, 20, 8}, {10, 3, 14}}
    };

    int sumL[3] = {0};
    int minL[3], maxL[3];
    float avgL[3];

    int sumT = 0;
    int minT = a[0][0][0];
    int maxT = a[0][0][0];
    float avgT;

    for (int x = 0; x < 3; x++)
    {
        int s = 0;
        int mn = a[x][0][0];
        int mx = a[x][0][0];

        printf("Layer %d:\n", x + 1);

        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                int v = a[x][y][z];
                printf("%4d", v);

                s += v;
                if (v < mn) mn = v;
                if (v > mx) mx = v;

                sumT += v;
                if (v < minT) minT = v;
                if (v > maxT) maxT = v;
            }
            printf("\n");
        }

        sumL[x] = s;
        minL[x] = mn;
        maxL[x] = mx;
        avgL[x] = (float)s / 9.0;

        printf("\nSum = %d\n", s);
        printf("Min = %d\n", mn);
        printf("Max = %d\n", mx);
        printf("Avg = %.2f\n\n", avgL[x]);
    }

    avgT = (float)sumT / 27.0;

    printf("Total Sum = %d\n", sumT);
    printf("Total Min = %d\n", minT);
    printf("Total Max = %d\n", maxT);
    printf("Total Avg = %.2f\n", avgT);

    return 0;
}
