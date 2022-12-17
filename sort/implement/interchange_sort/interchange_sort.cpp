#include <iostream>
#include "dynamic_array.cpp"

using  namespace std;

//best case: O(n^2)
//average case: O(n^2)
//worst case: O(n^2)
template <class T>
void interchangeSort(DynamicArray<T> &array)
{
    for (int i = 0; i < array.size - 1; i++)
    {
        for (int j = i; j < array.size; j++)
        {
            if (array.get(i) > array.get(j))
            {
                T temp = array.get(i);
                array.set(i, array.get(j));
                array.set(j, temp);
            }
        }
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
    interchangeSort(array);
    array.iterator();
    return 0;
}