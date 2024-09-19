#include <stdio.h>
#define M 2
#define N 3

void convert(int source[M][N]);
void print_matrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    int item[M][N] = {1, 2, 3, 4, 5, 6};

    // 打印原始矩阵
    print_matrix(M, N, item);

    // 转换矩阵
    convert(item);

    return 0;
}

// 打印矩阵的方法
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }
}

void convert(int source[M][N]) {
    int target[N][M] = {};  // 转置矩阵
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < N; k++) {
            target[k][i] = source[i][k];
        }
    }

    // 打印分隔线
    printf("=====\n");

    // 打印转换后的矩阵
    print_matrix(N, M, target);
}
