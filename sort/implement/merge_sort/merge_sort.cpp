#include <iostream>
#include "dynamic_array.cpp"
using namespace std;

template <class T>
void merge(DynamicArray<T> &array, int left, int mid, int right)
{
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;
    DynamicArray<T> leftArray(leftArraySize);
    DynamicArray<T> rightArray(rightArraySize);

    // copy to 2 array
    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray.add(array.get(left + i));
    }
    for (int i = 0; i < rightArraySize; i++)
    {
        rightArray.add(array.get(mid + 1 + i));
    }

    // merge 2 array
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    while(leftArrayIndex < leftArray.size && rightArrayIndex < rightArray.size)
    {
        if (leftArray.get(leftArrayIndex) < rightArray.get(rightArrayIndex))
        {
            array.set(left, leftArray.get(leftArrayIndex));
            leftArrayIndex++;
        }
        else
        {
            array.set(left, rightArray.get(rightArrayIndex));
            rightArrayIndex++;
        }
        left++;
    }

    while (leftArrayIndex < leftArray.size)
    {
        array.set(left, leftArray.get(leftArrayIndex));
        leftArrayIndex++;
        left++;
    }
    while (rightArrayIndex < rightArray.size)
    {
        array.set(left, rightArray.get(rightArrayIndex));
        rightArrayIndex++;
        left++;
    }
}


template <class T>
void mergeSort(DynamicArray<T> &array, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
}

template <class T>
void randomArray(DynamicArray<T> &array)
{
    for (int i = 1; i <= 100000000; i++)
    {
        array.add(rand() % 999);
    }
}

int main()
{
    DynamicArray<int> array;
    randomArray(array);

    clock_t start, end;
    double timeUse;
    start = clock();
    mergeSort(array, 0, array.size - 1);
    end = clock();
    timeUse = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << timeUse << endl;
    return 0;
}