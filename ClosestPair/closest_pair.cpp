#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void Sort_by_X_or_Y(double[], unsigned int[], int);
double Closest_Pair_DC(unsigned int, unsigned int, unsigned int*, unsigned int*, double*, double*,
	unsigned int*, unsigned int*, unsigned int*, int);
void MergeSort(double X[], int p, int q);
void Merge(double A[], double U[], int p, int k, int q);

void main() {
	FILE *fp;
	fopen_s(&fp, "C:/A.txt", "r");
	int nTest, nPoints, threshold;
	double *X = NULL;
	double *Y = NULL;
	double *Xid = NULL;
	unsigned int pt1, pt2;
	unsigned int *P1 = NULL;
	unsigned int *P2 = NULL;
	unsigned int *P3 = NULL;
	double cd;

	if (fp == NULL) {
		printf("file does not exist");
		exit(1);
	}
	if (fp) {	//파일 A.txt 내의 데이터를 읽어서 저장
		fscanf_s(fp, "%d %d %d", &nTest, &nPoints, &threshold);

		X = (double*)malloc(sizeof(double)*nPoints);
		Y = (double*)malloc(sizeof(double)*nPoints);
		Xid = (double*)malloc(sizeof(double)*nPoints);
		P1 = (unsigned int*)malloc(sizeof(unsigned int*)*nPoints);
		P2 = (unsigned int*)malloc(sizeof(unsigned int*)*nPoints);
		P3 = (unsigned int*)malloc(sizeof(unsigned int*)*nPoints);

		for (unsigned int i = 0; i < nPoints; i++) {
			fscanf_s(fp, "%le %le", &X[i], &Y[i]);
			P1[i] = i;
		}
	}


	Sort_by_X_or_Y(X, P1, nPoints);
	cd = Closest_Pair_DC(0, nPoints - 1, &pt1, &pt2, X, Y, P1, P2, P3, threshold);



	free(X), free(Y), free(Xid);
	fclose(fp);
	getchar();
	getchar();
	return;
}

void Sort_by_X_or_Y(double X[], unsigned int P[], int n) {
	// Merge Sort 알고리즘으로 X 배열 정렬



}

void MergeSort(double X[], int p, int q) {
	if (sizeof(X) < 2) return;
	int k;
	double temp;
	double* U = NULL;
	U = (double*)malloc((q - p + 1) * sizeof(double));
	if (p < q) {
		k = (p + q) / 2;
		MergeSort(X, p, k);
		MergeSort(X, k + 1, q);
		Merge(X, U, p, k, q);
		return;
	}
}

void Merge(double A[], double U[], int p, int k, int q) {
	int i = p;
	int j = k + 1;
	int d = p;

	while (i <= k && j <= q) {
		if (A[i] < A[j]) {
			U[d] = A[i]; i++;
		}
		else {
			U[d] = A[j]; j++;
		}
		d++;
	}
	if (i > k) {
		for (int a = j; a <= q; a++) {
			U[d] = A[a];
		}
		d++;
	}
	else {
		for (int a = i; a <= k; a++) {
			U[d] = A[a];
		}
		d++;
	}
	for (int i = p; i <= q; i++) {
		A[i] = U[i];
	}
	for (int i = p; i <= q; i++) {
	}

	return;
}

double Closest_Pair_DC(unsigned int L, unsigned int R, unsigned int *pt1, unsigned int *pt2, double *X, double *Y,
	unsigned int *P1, unsigned int *P2, unsigned int *P3, int THR) {


	return 2.3f;
}

