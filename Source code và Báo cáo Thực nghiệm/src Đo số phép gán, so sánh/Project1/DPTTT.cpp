﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void HoanVi(int &a, int &b) {
	int t = a; a = b; b = t;
}
void capPhatNgauNhien(int *&a, int n) {
	srand(time(NULL));
	int i = 0;
	a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		free(a);
	}
	else {
		while (i<n)
			a[i++] = rand() % (n + 1);
	}
}
void XuatMang(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n, double &sosanh, double &gan)
{
	int i, j, min_idx;
 
	for (i = 0; i < n - 1; i++)
	{ 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				sosanh++;
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
		gan += 4;
	}
}

void BubbleSort(int a[], int n, double &sosanh, double &gan) {
	for (int i = 0; i<n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				HoanVi(a[j], a[j - 1]);
				gan += 3;
			}
			sosanh++;
		}
	}
}

void QuickSort(int a[], int l, int r, double &sosanh, double &gan) {
	int i = l, j = r, x = a[(l + r) / 2]; gan++;
	do {
		while (a[i] < x) {
			sosanh++;
			i++;
		}
		sosanh++;
		while (a[j] > x) {
			sosanh++;
			j--;
		}
		sosanh++;
		if (i <= j) {
			HoanVi(a[i], a[j]); gan += 3;
			i++; j--;
		}
	} while (i < j);
	if (l < j)
		QuickSort(a, l, j, sosanh, gan);
	if (i < r)
		QuickSort(a, i, r, sosanh, gan);
}
void Merge(int a[], int left, int mid, int right, double &sosanh, double &gan) {
	int *temp;
	int i = left;
	int j = mid + 1;
	temp = new int[right - left + 1];
	for (int k = 0; k <= right - left; k++) {
		if (a[i] < a[j]) {
			temp[k] = a[i]; gan++;
			i++;
		}
		else {
			temp[k] = a[j]; gan++;
			j++;
		}
		sosanh++;
		if (i == mid + 1) {
			while (j <= right) {
				k++;
				temp[k] = a[j]; gan++;
				j++;
			}
			break;
		}
		if (j == right + 1) {
			while (i <= mid) {
				k++;
				temp[k] = a[i]; gan++;
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= right - left; k++) {
		a[left + k] = temp[k]; gan++;
	}
	delete temp;
}
void MergeSort(int a[], int left, int right, double &sosanh, double &gan) {
	if (right > left) {
		int mid;
		mid = (left + right) / 2;
		MergeSort(a, left, mid, sosanh, gan);
		MergeSort(a, mid + 1, right, sosanh, gan);
		Merge(a, left, mid, right, sosanh, gan);
	}
}

int getMax(int arr[], int n, double &sosanh, double &gan) {
	int mx = arr[0]; gan++;
	for (int i = 1; i < n; i++) {
		if (arr[i] > mx) {
			mx = arr[i]; gan++;
		}
		sosanh++;
	}
	return mx;
}
void countSort(int arr[], const int n, int exp, double &sosanh, double &gan) {
	int * output = (int*)malloc(n * sizeof(int));
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; gan++;
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++) {
		arr[i] = output[i]; gan++;
	}
	free(output);
}
void RadixSort(int arr[], int n, double &sosanh, double &gan) {
	int m = getMax(arr, n, sosanh, gan);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp, sosanh, gan);
}
void CopyDuLieu(int* a, int* &b, const int n) {
	b = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

int main() {
	int *selectionsort, *bubblesort, *shakersort, *shellsort, *quicksort, *mergesort, *heapsort, *radixsort;
	int n;
	double thoigian, sosanh, gan;
	clock_t start_t, end_t;
	printf("Nhap so phan tu can cap phat ngau nhien: ");  scanf_s("%d", &n);
	capPhatNgauNhien(selectionsort, n); // Cấp phát DL gốc 1 lần

	sosanh = gan = 0;
	CopyDuLieu(selectionsort, bubblesort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tInsertionSort\t------------\n\n");
	start_t = clock();
	selectionSort(selectionsort, n, sosanh, gan);
	//XuatMang(insertionsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.0f ms\n\n", sosanh, gan, thoigian);
	free(selectionsort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(bubblesort, quicksort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tBubbleSort\t------------\n\n");
	start_t = clock();
	BubbleSort(bubblesort, n, sosanh, gan);
	//XuatMang(bubblesort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.0f ms\n\n", sosanh, gan, thoigian);
	free(bubblesort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(quicksort, mergesort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tQuickSort\t------------\n\n");
	start_t = clock();
	QuickSort(quicksort, 0, n - 1, sosanh, gan);
	//XuatMang(quicksort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.0f ms\n\n", sosanh, gan, thoigian);
	free(quicksort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	CopyDuLieu(mergesort, radixsort, n); //Copy Dữ liệu gốc trước khi sắp xếp
	printf("----------\tMergeSort\t------------\n\n");
	start_t = clock();
	MergeSort(mergesort, 0, n - 1, sosanh, gan);
	//XuatMang(mergesort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.0f ms\n\n", sosanh, gan, thoigian);
	free(mergesort); //Giải phóng DL sau khi sắp xếp xong

	sosanh = gan = 0;
	printf("----------\tRadixSort\t------------\n\n");
	start_t = clock();
	RadixSort(radixsort, n, sosanh, gan);
	//XuatMang(radixsort, n);
	end_t = clock();
	thoigian = (float)(end_t - start_t) * 1000 / CLOCKS_PER_SEC;
	printf("So phep so sanh:%.0lf\nSo phep gan:\t%.0lf\nThoi gian:\t%.0f ms\n\n", sosanh, gan, thoigian);
	free(radixsort); //Giải phóng DL sau khi sắp xếp xong
	system("pause");
	return 0;
}