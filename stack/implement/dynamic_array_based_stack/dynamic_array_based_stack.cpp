#include <iostream>
#include "dynamic_array.cpp"
using namespace std;

template <class T>
struct DynamicArrayBasedStack
{
    DynamicArray<T> *array;
    int index;

    DynamicArrayBasedStack()
    {
        array = new DynamicArray<T>();
        index = -1;
    }

    ~DynamicArrayBasedStack()
    {
        delete array;
    }

    void push(T element)
    {
        ++index;
        array->add(element);
    }

    T pop()
    {
        if (isEmpty())
            throw runtime_error("Empty!");
        return array->removeAt(index--);
    }

    T top()
    {
        return array->get(index);
    }

    int size()
    {
        return array->size;
    }

    bool isEmpty()
    {
        return array->isEmpty();
    }

    void clear()
    {
        array->clear();
    }

    void iterator()
    {
        while (!isEmpty())
        {
            cout << pop() << " ";
        }
    }
};

int main()
{
    DynamicArrayBasedStack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << "size: " << stk.size() << endl;

    stk.iterator();
    return 0;
}