#include <iostream>
#include "dynamic_array.cpp"

using namespace std;

//best case: O(n^2)
//average case: O(n^2)
//worst case: O(n^2)
template <class T>
void selectionSort(DynamicArray<T> &array)
{
    for(int i = 0; i < array.size - 1; i++)
    {
        int valueMinIndex = i;
        for (int j = i + 1; j < array.size; j++)
        {
            if (array.get(j) < array.get(valueMinIndex))
            {
                valueMinIndex = j;
            }
        }

        //Swap
        int temp = array.get(i);
        array.set(i, array.get(valueMinIndex));
        array.set(valueMinIndex, temp);
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
    selectionSort(array);
    array.iterator();
    return 0;
}