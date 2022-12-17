#include <iostream>
using namespace std;

template <class T> 
struct DynamicArray
{
    T *arr;
    int capacity;
    int size;

    DynamicArray(int capacity)
    {
        if (capacity < 0) throw runtime_error("Invalid entry!");
        this->capacity = capacity;
        size = 0;
        arr = new T[capacity];
    }

    DynamicArray()
    {
        capacity = 10;
        arr = new T[capacity];
        size = 0;
    }

    ~ DynamicArray()
    {
        delete[] arr;
    }
    
    int isEmpty()
    {
        return size == 0;
    }

    T get(int index)
    {
        if (isEmpty()) throw runtime_error("Empty!");
        return arr[index];
    }

    void set(int index, T element)
    {
        if (index < 0 || index >= capacity)
            throw out_of_range("Index out of range!");
        if (isEmpty())
            throw runtime_error("Empty!");
        
        arr[index] = element;
    }

    void add(T element)
    {
        if (size >= capacity - 1)
        {
            if (capacity == 0)
            {
                capacity = 1;
            }
            else
            {
                capacity *= 2;
            }
            T *newArr = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = element;
    }

    T removeAt(int removeIndex)
    {
        if (removeIndex < 0 || removeIndex > size - 1) 
            throw out_of_range("Index out of range");
            
        T removeElement = arr[removeIndex];
        // Tạo newArr có size nhỏ hơn 1
        T *newArr = new T[size - 1];
        // Copy sang mảng mới, ngoại trừ element có index muốn xoá thì không copy
        int newArrIndex = 0, oldArrIndex = 0;
        while (oldArrIndex < size)
        {
            if (oldArrIndex == removeIndex)
                ++oldArrIndex;

            newArr[newArrIndex] = arr[oldArrIndex];

            ++newArrIndex;
            ++oldArrIndex;
        }

        // Xoá mảng cũ, set mảng mới vào biến của mảng cũ
        delete[] arr;
        arr = newArr;

        // Cập nhật lại capcity vì đã xoá đi 1 element
        capacity = --size;
        return removeElement;
    }

    int indexOf(T element)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }

    void remove(T removeElement)
    {
        int removeIndex = indexOf(removeElement);
        if (removeIndex == -1)
            return;
        removeAt(removeIndex);
    }

    bool contains(T element)
    {
        int index = indexOf(element);
        if (index == -1)
            return false;
        return true;
    }

    void clear()
    {
        delete[] arr;
        arr = new T[capacity];
        size = 0;
    }

    string toString()
    {
        if (size == 0)
            return "[]";

        string str = "";
        str.append("[");
        for (int i = 0; i < size; i++)
        {
            str.append(to_string(arr[i]));
            str.append(",");
        }
        
        str[str.length() - 1] = ']';
        return str;
    }

    void iterator()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};