#include <stdio.h>

typedef struct {                         // 행렬 원소를 저장하기 위한 구조체 SparseMatrix 정의
    int row;
    int col;
    int value;
} SparseMatrix;

void Transpose(SparseMatrix a[], SparseMatrix b[]) {
    int i, j, currentb;

    b[0].col = a[0].row;                 // 전치행렬 b의 행 수 = 희소행렬 a의 행 수
    b[0].row = a[0].col;                 // 전치행렬 b의 열 수= 희소행렬 a의 열 수
    b[0].value = a[0].value;             // 전치행렬 b의 원소 수 = 희소행렬 a에서 0이 아닌 원소수

    if (a[0].value > 0) {                  //0이 아닌 원소가 있는 경우에만 전치 연산 수행
        currentb = 1;
        for (i = 0; i < a[0].col; i++)            //희소행렬 a의 열별로 전치 반복 수행
            for (j = 1; j <= a[0].value; j++)   //0이 아닌 원소 수에 대해서만 반복 수행
                if (a[j].col == i) {                    //현재의 열에 속하는 원소가 있으면 b[]에 삽입
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}

int main(void) {
    int i, j;
    SparseMatrix A[8] = { {6, 6, 7}, {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} };
    SparseMatrix B[8];

    // 행의 수: A[0].row, 열의 수: A[0].col, 0이 아닌 항의 수: A[0].value

    for (i = 1; i < 8; i++)
        printf("%d %d %d\n", A[i].row, A[i].col, A[i].value);
    printf("\n");

    Transpose(A, B);

    // Transpose processing has been finished.
    printf("\n");

    // 행의 수: B[0].row, 열의 수: B[0].col, 0이 아닌 항의 수: B[0].value

    for (i = 1; i < 8; i++)
        printf("%d %d %d\n", B[i].row, B[i].col, B[i].value);
    printf("\n");
}
