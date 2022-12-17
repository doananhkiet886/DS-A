#include <iostream>
#include "dynamic_array.cpp"
using namespace std;

//best case: O(n^2)
//average case: O(n^2)
//worst case: O(n^2)
template <class T>
void insertionSort(DynamicArray<T> &array)
{
    for(int i = 1; i < array.size; i++)
    {
        int iValue = array.get(i);
        int j = i - 1;
        while(j >= 0 && array.get(j) > iValue)
        {
            array.set(j + 1, array.get(j));
            j--;
        }
        array.set(j + 1, iValue);
    }
}

int main()
{
    DynamicArray<int> array;
    array.add(5);
    array.add(2);
    array.add(7);
    array.add(0);
    array.add(9);
    insertionSort(array);
    array.iterator();
    return 0;
}