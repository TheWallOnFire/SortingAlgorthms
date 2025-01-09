#pragma once

#include <iostream>
#include <vector>

using FuncPtr = void (*)(int* arr, int n, long long& comps);

void commandLine(int argc, char* argv[]);
void testAlgorithm(const std::string name, int number);
void testAlgorithms(std::vector<std::string> name);

// ____________Algorithms___________________
void getAlgorithm(const char* name, FuncPtr& algo);


//# Nhóm thuật toán 1: (7 cái) -> 23h59 8/12/2024
//Selection Sort, Quick Sort->Quân
void SelectionSort(int* arr, int n, long long& comps);

void QuickSort(int* arr, int n, long long& comps);

//Insertion Sort, Bubble Sort->Hòa
void InsertionSort(int* arr, int n, long long& comps);

void BubbleSort(int* arr, int n, long long& comps);

//Heap Sort->Lộc
void HeapSort(int* arr, int n, long long& comps);

//Merge Sort->Khoa
void MergeSort(int* a, int n, long long& comps);

//Radix Sort->Tường
void RadixSort(int* arr, int n, long long& comps);



//# Nhóm thuật toán 2: (4 cái)
//Shaker Sort, -> Hòa
void ShakerSort(int* arr, int n, long long & comp);

//Shell Sort, -> Lộc
void ShellSort(int* arr, int n, long long & comp);

//Counting Sort, -> Khoa
void CountingSort(int* arr, int n, long long & comp);

//Flash Sort->Quân
void FlashSort(int* arr, int n, long long & comp);

