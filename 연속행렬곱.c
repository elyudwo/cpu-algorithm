#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int matrix[501][2];//첫번째[]=몇번째 행렬인지,두번째[]=0이면 행 1이면 열나타냄//
int DP[501][501];//최소곱 나타내는 배열//
int mat(int n);
int min(int x, int y) {
   return (x < y) ? x : y;
}

int main() {
   int n, i;
   printf("행렬의 개수 : \n");
   scanf("%d", &n);//n:행렬의 개수//
   printf("각 행렬의 행 과 열 입력:\n ");
   for (i = 0; i < n; i++) {
      scanf("%d %d", &matrix[i][0], &matrix[i][1]);//각 행렬의 행과 열 값 입력//
   }
   int result = mat(n);
   for(int i=0;i<n-1;i++) {
         if(matrix[i][1] != matrix[i+1][0]) {
             printf("올바르지 않은 접근입니다! \n");
             exit(1);
          }
   }
   printf("최소연산 횟수 : %d", result);

}
int mat(int n) {
   int a, b;
   int i, j, k;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n - i; j++) {
         a = j;
         b = j + i;
         if (a == b) {
            DP[a][b] = 0;
         }
         else {
            DP[a][b] = 1000000;
            for (k = a; k < b; k++) {
               DP[a][b] = min(DP[a][b], DP[a][k] + DP[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
            }
         }
      }
   }
   return DP[0][n - 1];
}