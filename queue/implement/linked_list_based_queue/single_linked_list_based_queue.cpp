#include <iostream>
#include "single_linked_list.cpp"

using namespace std;

template <class T>
struct SingleLinkedListBasedQueue
{
    SingleLinkedList<T> *linkedList;

    SingleLinkedListBasedQueue()
    {
        linkedList = new SingleLinkedList<T>();
    }

    ~ SingleLinkedListBasedQueue()
    {
        delete linkedList;
    }

    void enQueue(T element)
    {   
        linkedList->addTail(element);
    }

    T deQueue()
    {
        return linkedList->removeHead();
    }

    T peek()
    {
        return linkedList->peekHead();
    }

    int size()
    {
        return linkedList->size;
    }

    bool isEmpty()
    {
        return linkedList->isEmpty();
    }

    void clear()
    {
        return linkedList->clear();
    }

    void iterator()
    {
        while (!linkedList->isEmpty())
        {
            cout << linkedList->peekHead() << " ";
            linkedList->removeHead();
        }
    }
};

int main()
{
    SingleLinkedListBasedQueue<int> queue;
    cout << "\nSize: " << queue.size() << "\n";
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    cout << "\nSize: " << queue.size() << "\n";
    queue.deQueue();
    queue.iterator();
    
    return 0;
}