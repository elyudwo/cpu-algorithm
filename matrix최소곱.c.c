#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int matrix[501][2];//ù��°[]=���° �������,�ι�°[]=0�̸� �� 1�̸� ����Ÿ��//
int DP[501][501];//�ּҰ� ��Ÿ���� �迭//
int mat(int n);
int min(int x, int y) {
	return (x < y) ? x : y;
}

int main() {
	int n, i;
	printf("����� ���� : \n");
	scanf_s("%d", &n);//n:����� ����//
	printf("�� ����� �� �� �� �Է�:\n ");
	for (i = 0; i < n; i++) {
		scanf_s("%d %d", &matrix[i][0], &matrix[i][1]);//�� ����� ��� �� �� �Է�//
	}
	int result = mat(n);
	printf("�ּҿ��� Ƚ�� : %d", result);

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
//mat �ڵ� ���� : ������������ a=j,b=j+i�� ��츦 0���� ������ ���鼭 �غ��Ҵ�.
//i=0 j=0 �϶��� ��簪�� a==b�̹Ƿ� 0
//���������� else�� ���� DP=1000000���� �а��� �ּҰ��� �����ؾ��ϱ⶧���� ó���� ��û ū���� ������ ������ �� �ְ� �����Ѱ�
//DP[a][b]���� k=a����b���� ���� ������ DP[a][b]�� �ּҰ� ��츦 ���� �� �ִ�.
//�̷��� ������ �ּҰ����� DP[][]�迭�� ������ְ�
//���� ���ϴ� ���� DP[0][n-1]���� �� �迭�� ����Ǿ��ִ� ������ ���� ���̳��� ���α׷��� ������ ����� �̷������.
//�׸��� return DP[0][n-1]���ָ� �Է��� ��� �� �ּҰ��� ���� �� �ִ�