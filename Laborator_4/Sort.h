#pragma once
#include <initializer_list>
#include <vector>
#include <cstdarg>

class Sort
{
private:
    int* list;
    int count;
public:
    Sort(int numOfElements, int min, int max);
    Sort(const std::initializer_list<int> il);
    Sort(std::vector<int> vec, int numOfElements);
    Sort(int numOfElements,...);
    Sort(const char* str);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
private:
    void quickSort(int* arr, int left, int right, bool ascendent);
    int partition(int* arr, int left, int right, bool ascendent);
};