#include"Header.h"

void CreateArr_random(int*&a, int n)
{
	a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (RAND_MAX*RAND_MAX);
	}
}

void CreateArr_sorted(int*&a, int n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
}

void CreateArr_reversed(int*&a, int n)
{
	a = new int[n];
	for (int i = 0; i<n; i++)
	{
		a[i] = n - i;
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
	for (j = 0; j < n - i - 1; j++)
	if (a[j] > a[j + 1])
		swap(&a[j], &a[j + 1]);
}
void radixSort(int *a, int n)
{
	int i;
	int maxNumber = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > maxNumber)
			maxNumber = a[i];
	}

	int exp = 1;
	int *tmpBuffer = new int[n];
	while (maxNumber / exp > 0)
	{
		int decimalBucket[10] = { 0 };
		for (i = 0; i < n; i++)
			decimalBucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			decimalBucket[i] += decimalBucket[i - 1];
		for (i = n - 1; i >= 0; i--) {

			tmpBuffer[--decimalBucket[a[i] / exp % 10]] = a[i];
		}
		for (i = 0; i < n; i++) {
			a[i] = tmpBuffer[i];

		}
		exp *= 10;
	}
}
void quickSort(int *a, int l, int r)
{
	int i = l; int j = r; int  x = a[(l + r) / 2];
	do {
		while (a[i] < x) i++;
		while (a[j] > x)  j--;
		if (i <= j) {
			swap(&a[i], &a[j]);
			i++; j--;
		}
	} while (i < j);
	if (l < j)
		quickSort(a, l, j);
	if (i < r)
		quickSort(a, i, r);
}
void bubblesort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	{
		if (a[j] < a[j - 1])
		{
			swap(&a[j], &a[j - 1]);
		}
	}
}
void Shift(int *a, int l, int r)
{
	int   x, i, j;
	i = l;   j = 2 * l;
	x = a[i - 1];
	while (j <= r)
	{
		if (j < r)
		{
			if (a[j - 1] < a[j])
				j = j + 1;
		}
		if (a[j - 1] < x)	return;
		else
		{
			a[i - 1] = a[j - 1];
			a[j - 1] = x;
			i = j;
			j = 2 * i;
		}
	}
}
void  TaoHeap(int *a, int N)
{
	int   l;
	l = N / 2;
	while (l > 0)
	{
		Shift(a, l, N);
		l = l - 1;
	}
}
void  heapSort(int *a, int N)
{
	int   r;
	TaoHeap(a, N);
	r = N - 1; //gia tri thuc cua n
	while (r > 0)
	{
		swap(&a[0], &a[r]);
		r = r - 1;
		Shift(a, 1, r + 1);
	}
}
void insertionSort(int *a, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void selecTionSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (i != min)
			swap(&a[i], &a[min]);
	}
}
void Merge(int *a, int left, int mid, int right)
{
	int *temp;
	int i = left;
	int j = mid + 1;

	temp = new int[right - left + 1];

	for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
	{
		a[left + k] = temp[k];
	}
	delete temp;
}
void mergeSort(int *a, int left, int right)
{
	if (right > left)
	{
		int mid;
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
void shakerSort(int *a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(&a[i], &a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
void shellSort(int *a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
void FlashSort(int *&a, int n)
{
	int ng = (int)(0.45 * n);

	int *sg = (int*)calloc(ng + 1, sizeof(int));
	int *b = (int*)calloc(n, sizeof(int));

	// 1. Find max and min value
	int min_val = INT_MAX;
	int max_val = INT_MIN;
	for (int i = 0; i < n; ++i) {
		min_val = min(min_val, a[i]);
		max_val = max(max_val, a[i]);
	}

	double c = ((double)ng - 1) / (max_val - min_val);
	for (int i = 0; i < ng; ++i) {
		sg[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		int gi = (int)(c * (a[i] - min_val));
		++sg[gi];
	}

	// 3. In each group, calculate last index array
	for (int i = 0; i < ng; ++i) {
		sg[i + 1] += sg[i];
	}

	// 4. Permutation
	for (int i = 0; i < n; ++i) {
		int gi = (int)(c * (a[i] - min_val));
		int bi = sg[gi] - 1;
		b[bi] = a[i];
		--sg[gi];
	}

	// 5. Sort item list in each group, using insertion sort
	for (int gi = 0; gi < ng; ++gi) {
		int x = sg[gi];
		int y = sg[gi + 1];
		for (int i = x; i < y; ++i) {
			int t = b[i];
			int j = i - 1;
			for (; j >= 0 && b[j] >= t; --j) {
				b[j + 1] = b[j];
			}
			b[j + 1] = t;
		}
	}

	// 6. Update array a
	for (int i = 0; i < n; ++i) {
		a[i] = b[i];
	}

	free(b);
	free(sg);
}

void inThoiGian(ofstream &file, int h, int k, int n)
{
	int *a = NULL;

	if (k == 1)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		bubblesort(a, h);
		clock_t end = clock();
		cout << "-->Time run bubblesort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}
	else if (k == 2)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		selecTionSort(a, h);
		clock_t end = clock();
		cout << "-->Time run selectionsort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}
	else if (k == 3)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		insertionSort(a, h);
		clock_t end = clock();
		cout << "-->Time run InsertionSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}
	else if (k == 4)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		heapSort(a, h);
		clock_t end = clock();
		cout << "-->Time run heapSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}
	else if (k == 5)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		quickSort(a, 0, h - 1);
		clock_t end = clock();
		cout << "-->Time run QuickSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;

	}
	else if (k == 6)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		mergeSort(a, 0, h - 1);
		clock_t end = clock();
		cout << "-->Time run MergeSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}

	else if (k == 7)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		radixSort(a, h);
		clock_t end = clock();
		cout << "-->Time run RadixSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << ",";
		system("pause");
		delete[]a;
	}
	else if (k == 8)
	{
		if (n == 1)
		{
			CreateArr_sorted(a, h);
		}
		else if (n == 2)
		{
			CreateArr_reversed(a, h);
		}
		else if (n == 3)
		{
			CreateArr_random(a, h);
		}
		clock_t begin = clock();
		FlashSort(a, h);
		clock_t end = clock();
		cout << "-->Time run FlashSort  la: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
		file << (float)(end - begin) / CLOCKS_PER_SEC << "," << endl;
		system("pause");
		delete[]a;
	}
}

void sapXepSort(ofstream &file)
{
	int n;
	string size1 = "100", size2 = "1000", size3 = "5000", size4 = "10000", size5 = "50000", size6 = "100000";
	int h1 = 100, h2 = 1000, h3 = 5000, h4 = 10000, h5 = 50000, h6 = 100000;
	do{
		system("cls");
		cout << "0. Thoat." << endl;
		cout << "1. Sap xep voi du lieu CO THU TU (sorted)." << endl;
		cout << "2. Sap xep voi du lieu NGUOC THU TU (reversed)." << endl;
		cout << "3. Sap xep voi du lieu NGAU NHIEN (random)." << endl;
		cout << "Moi ban chon: ";
		cin >> n;
		switch (n)
		{
		case 0:
		{exit(0);
		break;
		}
		case 1:
		{
				  cout << "==> DU LIEU CO THU TU(SORTED):" << endl;
				  cout << "==============================" << endl;
				  file << "Sorted" << "," << size1 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h1 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h1, i, 1);
				  }
				  file << "Sorted" << "," << size2 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h2 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++, 1)
				  {
					  inThoiGian(file, h2, i, 1);
				  }file << "Sorted" << "," << size3 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h3 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h3, i, 1);
				  }file << "Sorted" << "," << size4 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h4 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h4, i, 1);
				  }file << "Sorted" << "," << size5 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h5 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h5, i, 1);
				  }file << "Sorted" << "," << size6 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h6 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h6, i, 1);
				  }
				  break;
		}
		case 2:
		{
				  cout << "DU LIEU NGUOC THU TU(reversed):" << endl;
				  cout << "==============================" << endl;
				  file << "Reversed" << "," << size1 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h1 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h1, i, 2);
				  }
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h2 << " phan tu:" << endl;
				  file << "Reversed" << "," << size2 << ",";
				  for (int i = 1; i <= 8; i++, 2)
				  {
					  inThoiGian(file, h2, i, 2);
				  }
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h3 << " phan tu:" << endl;
				  file << "Reversed" << "," << size3 << ",";
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h3, i, 2);
				  }file << "Reversed" << "," << size4 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h4 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h4, i, 2);
				  }file << "Reversed" << "," << size5 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h5 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h5, i, 2);
				  }file << "Reversed" << "," << size6 << ",";
				  cout << "\nCHUONG TRINH DANG CHAY VOI DU LIEU CO " << h6 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h6, i, 2);
				  }
				  break;
		}
		case 3:
		{
				  cout << "==> DU LIEU NGAU NHIEN(Random):" << endl;
				  cout << "==============================" << endl;
				  file << "Random" << "," << size1 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h1 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h1, i, 3);
				  }
				  file << "Random" << "," << size2 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h2 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++, 3)
				  {
					  inThoiGian(file, h2, i, 3);
				  }file << "Random" << "," << size3 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h3 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h3, i, 3);
				  }file << "Random" << "," << size4 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h4 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h4, i, 3);
				  }file << "Random" << "," << size5 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h5 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h5, i, 3);
				  }file << "Random" << "," << size6 << ",";
				  cout << "\nChuong trinh dang chay voi du lieu co " << h6 << " phan tu:" << endl;
				  for (int i = 1; i <= 8; i++)
				  {
					  inThoiGian(file, h6, i, 3);
				  }
				  break;
		}
		default:
			break;
		}
	} while (n != 4);

}

void run()
{
	ofstream file;
	file.open("Result.csv", ios::app);
	file << "Case" << "," << "Size" << "," << "Bubble" << "," << "Selection" << "," << "Insertion" << "," << "Heap" << "," << "Quick" << "," << "Merge" << "," << "Radix" << "," << "Flash" << endl;
	sapXepSort(file);
	file.close();
}



