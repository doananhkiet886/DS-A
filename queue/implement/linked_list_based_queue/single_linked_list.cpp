#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;

    Node(T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

template <class T>
struct SingleLinkedList
{
    int size;
    Node<T> *head;
    Node<T> *tail;
    SingleLinkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    ~ SingleLinkedList()
    {
        clear();
    }
    
    void clear()
    {
        Node<T> *currentNode = head;
        while(currentNode != NULL)
        {
            Node<T> *nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void addHead(T value)
    {
        if(isEmpty())
        {
            head = tail = new Node<T>(value, NULL);
        }
        else
        {
           Node<T> *newNode = new Node<T>(value, head);
           head = newNode;
        }
        ++size;
    }

    void addTail(T value)
    {
        if(isEmpty())
        {
            head = tail = new Node<T>(value, NULL);
        }
        else
        {
            Node<T> *newNode = new Node<T>(value, NULL);
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void addAt(T value, int index)
    {
        if(index < 0 || index > size)
        {
            throw out_of_range("Index out of range!");
        }

        if(index == 0)
        {
            addHead(value);
            return;
        }
        if(index == size)
        {
            addTail(value);
            return;
        }

        Node<T> *currentNode = head;
        int currentIndex = 0;
        while(currentNode != NULL)
        {
            if (currentIndex == index - 1)
            {
                Node<T> *newNode = new Node<T>(value, currentNode->next);
                currentNode->next = newNode;
                break;
            }
            currentNode = currentNode->next;
            ++currentIndex;
        }
        ++size;
    }

    T peekHead()
    {
        if (isEmpty())
            throw runtime_error("Empty!");
        return head->data;
    }

    T peekTail()
    {
        if (isEmpty())
            throw runtime_error("Empty!");
        return tail->data;
    }

    T removeHead()
    {
        if(isEmpty())
        {
            throw runtime_error("Empty!");
        }

        T removeData = head->data;

        Node<T> *removeNode = head;
        head = head->next;
        --size;
        delete removeNode;
        if(isEmpty())
        {
            tail = NULL;
        }

        return removeData;
    }

    T removeTail()
    {
        if(isEmpty())
        {
            throw runtime_error("Empty!");
        }

        T removeData = tail->data;

        Node<T> *currentNode = head;
        while (currentNode->next != tail)
        {
            currentNode = currentNode->next;
        }
        delete tail;
        currentNode->next = NULL;   
        tail = currentNode;
        --size;
        if(isEmpty())
        {
            head = NULL;
        }
        
        return removeData;
    }

    T remove(Node<T> *node)
    {
        if(node == NULL)
        {
            throw runtime_error("Null pointer!");
        }

        if(node == head)
        {
            return removeHead();
        }
        if(node == tail)
        {
            return removeTail();
        }

        T removeData = node->data;

        Node<T> *currentNode = head;
        while (currentNode->next != node)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = node->next;
        delete node;
        --size;

        return removeData;
    }

    bool remove(T value)
    {
        Node<T> *currentNode = head;
        while(currentNode != NULL)
        {
            if(currentNode->data == value)
            {
                remove(currentNode);
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;   
    }

    T removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range!");
        }

        Node<T> *currentNode = head;
        int currentIndex = 0;
        while (currentIndex != index)
        {
            currentNode = currentNode->next;
            ++currentIndex;
        }
        return remove(currentNode);
    }

    int indexOf(T value)
    {
        int index = 0;
        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            if (currentNode->data == value)
            {
                return index;
            }
            currentNode = currentNode->next;
            ++index;
        }
        return -1;
    }

    bool contains(T value)
    {
        return indexOf(value) != -1;
    }


    void iterator()
    {
        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
    string toString()
    {
        string str = "[";

        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            str.append(to_string(currentNode->data));
            if (currentNode->next != NULL)
            {
                str.append(", ");
            }
            currentNode = currentNode->next;
        }
        str.append("]");
        
        return str;
    }
};