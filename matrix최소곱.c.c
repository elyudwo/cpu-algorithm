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
	scanf_s("%d", &n);//n:행렬의 개수//
	printf("각 행렬의 행 과 열 입력:\n ");
	for (i = 0; i < n; i++) {
		scanf_s("%d %d", &matrix[i][0], &matrix[i][1]);//각 행렬의 행과 열 값 입력//
	}
	int result = mat(n);
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
//mat 코드 설명 : 이중포문에서 a=j,b=j+i의 경우를 0부터 손으로 쓰면서 해보았다.
//i=0 j=0 일때는 모든값이 a==b이므로 0
//나머지부터 else문 적용 DP=1000000으로 둔것은 최소값을 저장해야하기때문에 처음엔 엄청 큰수로 무조건 대입할 수 있게 지정한것
//DP[a][b]에서 k=a부터b까지 포문 돌리면 DP[a][b]의 최소곱 경우를 구할 수 있다.
//이렇게 구해진 최소곱들은 DP[][]배열에 저장되있고
//최종 구하는 값인 DP[0][n-1]값은 위 배열에 저장되어있는 값들을 통해 다이나믹 프로그래밍 구조로 계산이 이루어진다.
//그리고 return DP[0][n-1]해주면 입력한 행렬 의 최소곱을 얻을 수 있다