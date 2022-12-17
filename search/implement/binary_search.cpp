#include <iostream>
#include "dynamic_array.cpp"
#include <time.h>
using namespace std;

template <class T>
int binarySearch(DynamicArray<T> &array, long left, long right, T key)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    
    if (key < array.get(mid))
        return binarySearch(array, left, mid - 1, key);
    if (key > array.get(mid))
        return binarySearch(array, mid + 1, right, key);
    return mid;
}

template <class T>
void enterAutoArray(DynamicArray<T> &array)
{
    for (int i = 0; i < 1000000; i++)
    {
        array.add(i);
    }
}
int main()
{
    DynamicArray<int> array;
    enterAutoArray(array);
    cout << binarySearch(array, 0, array.size - 1, 123) << endl;
    return 0;
}