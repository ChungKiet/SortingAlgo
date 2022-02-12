#include "Sort.h"

int main() {
	string LIST_SORT[] = { "Selection sort","Insertion sort","Binary-Insertion sort","Bubble sort","Shaker sort","Shell sort","Heap sort","Merge sort","Quick sort","Counting sort","Radix sort","Flash sort" };
	
	/*ofstream f("result_test.txt");
	
	for (string SORT : LIST_SORT) {
		Execute(SORT);
	}
	
	f.close();*/

	int choose = 7;// Xem danh sach ben duoi va nhao lua chon cua ban
	string SORT = LIST_SORT[choose - 1];
	Execute(SORT);


	return 0;
}

//----------------LIST-SORT----------------
// 1.     Selection sort
// 2.     Insertion sort
// 3.     Binary-Insertion sort
// 4.     Bubble sort
// 5.     Shaker sort
// 6.     Shell sort
// 7.     Heap sort
// 8.     Merge sort
// 9.     Quick sort
// 10.    Counting sort
// 11.    Radix sort
// 12.    Flash sort