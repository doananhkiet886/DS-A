#include <iostream>
#include "dynamic_array.cpp"

template <class T>
struct DynamicArrayBasedQueue
{
    DynamicArray<T> *array;

    DynamicArrayBasedQueue()
    {
        array = new DynamicArray<T>();
    }

    ~ DynamicArrayBasedQueue()
    {
        delete array;
    }
    
    void enQueue(T element)
    {
        array->add(element);
    }

    T deQueue()
    {
        return array->removeAt(0);
    }

    T peek()
    {
        return array->get(0);
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
        array->iterator();
        array->clear();
    }
};

int main()
{
    DynamicArrayBasedQueue<int> queue;
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.deQueue();
    queue.enQueue(4);
    queue.iterator();
    return 0;
}