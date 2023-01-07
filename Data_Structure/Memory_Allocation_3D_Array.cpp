#include <stdio.h>
#include <stdlib.h>

#define X 2
#define Y 3
#define Z 4 //2x3x4 3D Array

// Memory Allocation of 3D Array
int main()
{
    int*** A = (int***)malloc(X * sizeof(int**)); //memory allocation

    if (A == NULL)
    {
        fprintf(stderr, "Out of memory");
        exit(0);
    }

    for (int i = 0; i < Y; i++)
    {
        A[i] = (int**)malloc(Y * sizeof(int*));

        if (A[i] == NULL)
        {
            fprintf(stderr, "Out of memory");
            exit(0);
        }

        for (int j = 0; j < Z; j++)
        {
            A[i][j] = (int*)malloc(Z * sizeof(int));
            if (A[i][j] == NULL)
            {
                fprintf(stderr, "Out of memory");
                exit(0);
            }
        }
    }

    // assign values to the allocated memory 할당된 메모리에 값을 할당
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            for (int k = 0; k < Z; k++) {
                A[i][j][k] = rand() % 100;
            }
        }
    }

    // print the 3D array 3차원 배열 출력
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            for (int k = 0; k < Z; k++) {
                printf("%d ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Memory Deallocation of 3D array 동적 메모리 할당 해제
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++) {
            free(A[i][j]); //deallocation memory 메모리 해제
        }
        free(A[i]);
    }
    free(A);

    return 0;
}