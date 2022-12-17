#include <iostream>
#include "dynamic_array.cpp"
using namespace std;

//best case: O(n^2)
//average case: O(n^2)
//worst case: O(n^2)
template <class T>
void bubleSort(DynamicArray<T> &array)
{
    for(int i = 0; i < array.size - 1; i++)
    {
        for (int j = 0; j < array.size - i - 1; j++)
        {
            if (array.get(j) > array.get(j + 1))
            {
                //Swap
                int temp = array.get(j);
                array.set(j, array.get(j + 1));
                array.set(j + 1, temp);
            }
        }
    }
};

int main()
{
    DynamicArray<int> array;
    array.add(5);
    array.add(2);
    array.add(7);
    array.add(0);
    array.add(9);
    bubleSort(array);
    array.iterator();
    return 0;
}