#ifndef _LIBDEVDEFINE_H_
#define _LIBDEVDEFINE_H_

#include<iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
void CreateArr_random(int*&a, int n);
void CreateArr_sorted(int*&a, int n);
void CreateArr_reversed(int*&a, int n);
void swap(int *a, int *b);
void bubbleSort(int *a, int n);
void radixSort(int *a, int n);
void quickSort(int *a, int l, int r);
void bubblesort(int *a, int n);
void Shift(int *a, int l, int r);
void  TaoHeap(int *a, int N);
void  heapSort(int *a, int N);
void insertionSort(int *a, int n);
void selecTionSort(int *a, int n);
void Merge(int *a, int left, int mid, int right);
void mergeSort(int *a, int left, int right);
void shakerSort(int *a, int n);
void shellSort(int *a, int n);
void FlashSort(int *&a, int n);
int min(int a, int b);
int max(int a, int b);
void FlashSort(int *&a, int n);
void inThoiGian(ofstream &file, int h, int k, int n);
void sapXepSort(ofstream &file);
void run();

#endif