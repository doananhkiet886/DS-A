#include <iostream>
using namespace std;

template <class T>
struct SimpleArrayBasedQueue
{
    T *array;
    int front;
    int rear;
    int capacity;
    int size;

    SimpleArrayBasedQueue(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        front = rear = 0;
        array = new T[capacity];
    }

    ~ SimpleArrayBasedQueue()
    {
        delete[] array;
    }

    void enQueue(T element)
    {
        if (isFull())
            throw runtime_error("Queue is full!");

        array[rear] = element;
        ++rear;
        ++size;

        if (rear == capacity)
            rear = 0;        
    }

    T deQueue()
    {
        if (isEmpty())
            throw runtime_error("Queue is empty!");
        
        T element = array[front];
        ++front;
        --size;

        if (front == capacity)
            front = 0;
        
        return element;
    }

    T peek()
    {
        return array[front];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void iterator()
    {
        int i = front;
        int count = 1;
        while (count <= size)
        {
            if (i == capacity)
                i = 0;
            cout << array[i] << " ";
            i++;
            count++;
        }
    }
};

int main()
{
    SimpleArrayBasedQueue<int> queue(2);
    queue.enQueue(1);
    queue.enQueue(2);
    try
    {
        queue.enQueue(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    queue.iterator();
    return 0;
}