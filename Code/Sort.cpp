#include "Sort.h"
#include "DataGenerator.h"
void Selection_Sort(int* arr, int n) {
	int min = 0,temp = 0;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[min] > arr[j])
				min = j;
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void Insertion_Sort(int* arr, int n) {
	int i = 0;
	int x = 0, pos = 0;
	for (i = 1; i < n; i++) {
		x = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > x) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = x;
	}
}

void Interchange_Sort(int* arr, int size) {
	int temp = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Bubble_Sort(int* arr, int size) {
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = size - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void Shaker_Sort(int* arr, int size) {
	int l = 0, r = size - 1, k = size - 1, j = 0, temp = 0;
	while (l < r) {
		j = r;
		while (j > l) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				k = j;
			}
			j--;
		}
		l = k;
		j = l;
		while (j < r) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				k = j;
			}
			j++;
		}
		r = k;
	}
}

void BinaryInsertion_Sort(int* arr, int size) {
	int l = 0, r = 0, x = 0, mid = 0, pos = 0;
	for (int i = 1; i < size; i++) {
		l = 0, r = i - 1;
		mid = (i - 1) / 2;
		x = arr[i];
		while (l <= r) {
			mid = (l + r) / 2;
			if (x > arr[mid])
				l = mid + 1;
			else
				r = mid - 1;
		}
		pos = i - 1;
		while (pos >= l) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = x;
	}
}

void Support_Merge_Sort(int* arr, int l, int r) {
	int x = 0, i = 0, pos = 0;
	for (i = l + 1; i <= r; i++) {
		x = arr[i];
		pos = i - 1;
		while (pos >= l && arr[pos] > x) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = x;
	}
}

void Merge(int* arr, int l, int mid, int r) {
	if (r - l + 1 <= 4) {
		Support_Merge_Sort(arr, l, r);
		return;
	}
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int* arr_l = new int[n1];
	int* arr_r = new int[n2];
	for (int i = 0; i < n1; i++)
		arr_l[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		arr_r[i] = arr[mid + i + 1];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (arr_l[i] < arr_r[j]) {
			arr[k] = arr_l[i];
			i++;
			k++;
		}
		else {
			arr[k] = arr_r[j];
			j++;
			k++;
		}
	}

	while (i < n1) {
		arr[k] = arr_l[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = arr_r[j];
		j++;
		k++;
	}
	delete[] arr_l;
	delete[]arr_r;
}

void ExMerge_Sort(int* arr, int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		ExMerge_Sort(arr, l, mid);
		ExMerge_Sort(arr, mid + 1, r);
		Merge(arr, l, mid, r);
	}
}

void Merge_Sort(int* arr, int size) {
	ExMerge_Sort(arr, 0, size - 1);
}

void Shift(int* arr, int l, int r) {
	int i = l;
	int j = 2 * i + 1;
	int x = arr[l];
	while (j <= r) {
		if (j < r) {
			if (arr[j] < arr[j + 1])
				j++;
		}
		if (arr[j] <= x) {
			break;
		}
		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}
	arr[i] = x;
}

void Make_Heap(int* arr, int size) {
	int l = size / 2 - 1;
	int r = size - 1;
	while (l >= 0) {
		Shift(arr, l, r);
		l--;
	}
}

void Heap_Sort(int* arr, int size) {
	int r = size - 1, temp = 0;
	Make_Heap(arr, size);
	while (r >= 1) {
		temp = arr[0];
		arr[0] = arr[r];
		arr[r] = temp;
		r--;
		Shift(arr, 0, r);
	}
}

void ExQuick_Sort(int* arr, int l, int r) {
	int i = l, j = r, temp = 0;
	int x = arr[(i + j) / 2];
	do {
		while (arr[i] < x)i++;
		while (arr[j] > x)j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > l) ExQuick_Sort(arr, l, j);
	if (i < r) ExQuick_Sort(arr, i, r);
}

void Quick_Sort(int* arr, int size) {
	ExQuick_Sort(arr, 0, size - 1);
}

void Counting_Sort(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	int* b = new int[max + 1];
	for (int i = 0; i < max + 1; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < size; i++)
		b[arr[i]]++;
	for (int i = 1; i < max + 1; i++)
		b[i] += b[i - 1];
	int* res = new int[size];
	for (int i = 0; i < size; i++) {
		res[b[arr[i]] - 1] = arr[i];
		b[arr[i]]--;
	}
	for (int i = 0; i < size; i++)
		arr[i] = res[i];
	delete[]res;
	delete[]b;
}

int Create_H(int*& h, int size) {
	int count = 0;
	int len = size, i = 0;
	while (len > 1) {
		count++;
		len /= 2;
	}
	h = new int[count];
	while (size > 1) {
		h[i] = size / 2;
		size /= 2;
		i++;
	}
	return count;
}

void ShellSort_By_Step(int* arr, int size, int* h, int step) {
	int x = 0, pos = 0;
	for (int i = 0; i < step; i++) {
		int len = h[i];
		for (int j = len; j < size; j++) {
			x = arr[j];
			pos = j - len;
			while (pos >= 0 && arr[pos] > x) {
				arr[pos + len] = arr[pos];
				pos -= len;
			}
			arr[pos + len] = x;
		}
	}
}

void Shell_Sort(int* arr, int size) {
	int* h;
	int count = Create_H(h, size);
	ShellSort_By_Step(arr, size, h, count);
	if (h)
		delete[]h;
}

int lenmax(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	int len = 0;
	while (max > 0) {
		len += 1;
		max /= 10;
	}
	return len;
}

int DiGit(int digit, int k) {
	int res = digit / pow(10, k - 1);
	return res % 10;
}

void Sort(int* arr, int size, int k) {
	int* f = new int[10], j = 0;
	for (int i = 0; i < 10; i++)
		f[i] = 0;
	for (int i = 0; i < size; i++)
		f[DiGit(arr[i], k)]++;
	for (int i = 1; i < 10; i++)
		f[i] += f[i - 1];
	int* res = new int[size];
	for (int i = size - 1; i >= 0; i--) {
		j = DiGit(arr[i], k);
		res[f[j] - 1] = arr[i];
		f[j]--;
	}
	for (int i = 0; i < size; i++)
		arr[i] = res[i];
	delete[]res;
	delete[]f;
}

void Radix_Sort(int* arr, int size) {
	int d = lenmax(arr, size);
	for (int i = 1; i <= d; i++) {
		Sort(arr, size, i);
	}
}

int getMax(int* a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (max < a[i])max = a[i];
	return max;
}

void BitwiseRadixSort(int* a, int n)
{
	int* b = new int[n];
	int max = getMax(a, n), shift = 0;

	while ((max >> shift) > 0) {
		int count[2] = { 0,0 };
		for (int i = 0; i < n; i++)
			count[((a[i] >> shift) & 1)]++;

		count[1] += count[0];

		for (int i = n - 1; i >= 0; i--) {
			b[--count[((a[i] >> shift) & 1)]] = a[i];
		}
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		shift++;
	}
}

void LSDRadixSort(int* a, int n)
{
	int* b = new int[n];
	int max = getMax(a, n);
	int digit = 1;

	while (max / digit > 0) {
		int count[10] = { 0 };
		for (int i = 0; i < n; i++)
			count[(a[i] / digit) % 10]++;
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = n - 1; i >= 0; i--) {
			b[--count[(a[i] / digit) % 10]] = a[i];
		}
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		digit *= 10;
	}
}

int Max_Arr(int* arr, int size) {
	if (!arr || size <= 0)
		return -1000000000;
	int res = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > res)
			res = arr[i];
	return res;
}

int Min_Arr(int* arr, int size) {
	if (!arr || size <= 0)
		return 1000000000;
	int res = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < res)
			res = arr[i];
	return res;
}

void Flash_sort(int* arr, int size) {
	int m = 0.43 * size;
	if (!arr || size <= 0)
		return;
	int k = 0;
	int* L = new int[m];
	for (int i = 0; i < m; i++)
		L[i] = 0;
	int MAX = Max_Arr(arr, size);
	int MIN = Min_Arr(arr, size);

	for (int i = 0; i < size; i++) {
		k = (m - 1) * double((arr[i] - MIN) * 1.0 / (MAX - MIN));
		L[k]++;
	}
	for (k = 1; k < m; k++) {
		L[k] += L[k - 1];
	}
	int count = 0, i = 0, x = 0, y = 0, t = 0, j = 0;
	k = m - 1;
	while (count < size) {
		while (i >= L[k]) {
			i++;
			k = (m - 1) * double((arr[i] - MIN) * 1.0 / (MAX - MIN));
		}
		x = arr[i];
		while (i < L[k]) {
			k = (m - 1) * double((x - MIN) * 1.0 / (MAX - MIN));
			y = arr[L[k] - 1];
			arr[L[k] - 1] = x;
			x = y;
			L[k]--;
			count++;
		}
	}
	for (k = 1; k < m; k++) {
		for (i = L[k] - 2; i > L[k - 1]-1; i--) {
			if (arr[i] > arr[i + 1]) {
				t = arr[i];
				j = i;
				while (t > arr[j + 1]) {
					arr[j++] = arr[j + 1];
				}
				arr[j] = t;
			}
		}
	}
	
	delete[]L;
}

void CASE(void(*&Sort)(int* arr, int size),string SORT) {
	if (SORT == "Selection sort") {
		Sort = Selection_Sort;
	}
	else if (SORT == "Insertion sort") {
		Sort = Insertion_Sort;
	}
	else if (SORT == "Binary-Insertion sort") {
		Sort = BinaryInsertion_Sort;
	}
	else if (SORT == "Bubble sort") {
		Sort = Bubble_Sort;
	}
	else if (SORT == "Shaker sort") {
		Sort = Shaker_Sort;
	}
	else if (SORT == "Shell sort") {
		Sort = Shell_Sort;
	}
	else if (SORT == "Heap sort") {
		Sort = Heap_Sort;
	}
	else if (SORT == "Merge sort") {
		Sort = Merge_Sort;
	}
	else if (SORT == "Quick sort") {
		Sort = Quick_Sort;
	}
	else if (SORT == "Counting sort") {
		Sort = Counting_Sort;
	}
	else if (SORT == "Radix sort") {
		Sort = Radix_Sort;
	}
	else if (SORT == "Flash sort") {
		Sort = Flash_sort;
	}
	else {
		cout << "Error!" << endl;
	}
}

void ExecuteSort(string SORT,int n){//ofstream &f) {
	int* arr = new int[n];
	//stringstream write;
	

	void (*Sort)(int* arr, int size) = Quick_Sort;
	CASE(Sort, SORT);

	cout << "n = " << n << endl;

	GenerateRandomData(arr, n);
	cout << "Randomly generated: ";
	auto t1 = chrono::high_resolution_clock::now();
	Sort(arr, n);
	auto t2 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microsecond(s)" << endl;
	
	GenerateSortedData(arr, n);
	cout << "Sorted:             ";
	t1 = chrono::high_resolution_clock::now();
	Sort(arr, n);
	t2 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microsecond(s)" << endl;

	GenerateNearlySortedData(arr, n);
	cout << "Nearly sorted:      ";
	t1 = chrono::high_resolution_clock::now();
	Sort(arr, n);
	t2 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microsecond(s)" << endl;

	GenerateReverseData(arr, n);
	cout << "Reversed:           ";
	t1 = chrono::high_resolution_clock::now();
	Sort(arr, n);
	t2 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microsecond(s)" << endl;

	cout << endl;
	
	delete[]arr;
}

void Execute(string SORT){//,ofstream &f) {
	int SIZE[] = { 3000,10000,30000,100000,300000 };
	
	cout << SORT << ":" << endl;

	for (int size : SIZE) {
		ExecuteSort(SORT, size);
	}
}