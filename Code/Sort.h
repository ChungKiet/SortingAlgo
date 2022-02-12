#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <cmath>
using namespace std;

void Selection_Sort(int* arr, int n);

void Insertion_Sort(int* arr, int n);

void Interchange_Sort(int* arr, int size);

void Shaker_Sort(int* arr, int size);

void BinaryInsertion_Sort(int* arr, int size);

void ExMerge_Sort(int* arr, int l, int r);

void Merge_Sort(int* arr, int size);

void Shift(int* arr, int l, int r);

void Make_Heap(int* arr, int size);

void Heap_Sort(int* arr, int size);

void ExQuick_Sort(int* arr, int l, int r);

void Quick_Sort(int* arr, int size);

void Counting_Sort(int* arr, int size);

int Create_H(int*& h, int size);

void ShellSort_By_Step(int* arr, int size, int* h, int step);

void Shell_Sort(int* arr, int size);

int lenmax(int* arr, int size);

int DiGit(int digit, int k);

void Sort(int* arr, int size, int k);

void Radix_Sort(int* arr, int size);

int Max_Arr(int* arr, int size);

int Min_Arr(int* arr, int size);

void Flash_sort(int* arr, int size);

void ExecuteSort(string SORT, int n);// , ofstream& f);

void Execute(string SORT);// , ofstream& f);

