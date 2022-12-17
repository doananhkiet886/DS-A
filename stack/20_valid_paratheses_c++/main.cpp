#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char ch;
    Node *pNext;
};

struct Stack
{
    Node *pTop;
};

void initialize(Stack &stack)
{
    stack.pTop = nullptr;
}

Node* createNode(char ch)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        return nullptr;
    }
    
    newNode->ch = ch;
    newNode->pNext = nullptr;
    return newNode;
}

bool isEmpty(Stack stack)
{
    return stack.pTop == nullptr;
}

bool push(Stack &stack, char ch)
{
    Node *newNode = createNode(ch);
    if (newNode == nullptr)
    {
        return false;
    }

    if (isEmpty(stack))
    {
        stack.pTop = newNode;
    }
    else
    {
        newNode->pNext = stack.pTop;
        stack.pTop = newNode;
    }
    return true;
}

bool pop(Stack &stack, char &ch)
{
    if (isEmpty(stack))
    {
        return false;
    }

    ch = stack.pTop->ch;
    Node *temp = stack.pTop;
    stack.pTop = stack.pTop->pNext;
    delete temp; 
    return true;
}

bool top(Stack stack, char &ch)
{
    if (isEmpty(stack))
    {
        return false;
    }

    ch = stack.pTop->ch;
    return true;
}

bool isValid(string str)
{
    Stack stack;
    initialize(stack);
    int strLen = str.length();
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(stack, str[i]);
        }
        else
        {
            char prevBracket;
            pop(stack, prevBracket);
            if (prevBracket == '(' && str[i] == ')')
            {
                continue;
            }
            else if (prevBracket == '[' && str[i] == ']')
            {
                continue;
            }
            else if (prevBracket == '{' && str[i] == '}')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    if (isEmpty(stack))
    {
        return true;
    }
    return false;
}
int main()
{
    string str = "{[()]}";
    cout << isValid(str) << endl;
    return 0;
}