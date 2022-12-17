#include <iostream>
#include "single_linked_list.cpp"
using namespace std;

template <class T>
struct SingleLinkedListBasedStack
{
    SingleLinkedList<T> *linkedList;

    SingleLinkedListBasedStack()
    {
        linkedList = new SingleLinkedList<T>();
    }

    ~ SingleLinkedListBasedStack()
    {
        delete linkedList;
    }

    void push(T element)
    {
        linkedList->addHead(element);
    }

    T pop()
    {
        if (isEmpty()) throw runtime_error("Empty!");

        return linkedList->removeHead();
    }

    T top()
    {
        return linkedList->peekHead();
    }

    int size()
    {
        return linkedList->size();
    }

    bool isEmpty()
    {
        return linkedList->isEmpty();
    }

    void clear()
    {
        linkedList->clear();
    }

    void iterator()
    {
        T currentElement;
        while(!linkedList->isEmpty())
        {
            currentElement = linkedList->removeHead();
            cout << currentElement << " ";
        }
        cout << endl;
    }
};

int main()
{
    SingleLinkedListBasedStack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.iterator();
    return 0;
}