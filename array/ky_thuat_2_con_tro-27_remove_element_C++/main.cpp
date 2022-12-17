#include <iostream>
using namespace std;

void inputArray(int arr[], int number)
{
    int iCur = 0;
    while (iCur < number)
    {
        cin >> arr[iCur];
        iCur++;
    }
}

void printArray(int arr[], int number)
{
    int iCur = 0;
    while(iCur < number)
    {
        cout << arr[iCur] << " ";
        iCur++;
    }
    cout << endl;
}

int removeElement(int arr[], int number, int value)
{
    int iToDelete = 0;
    int iCur = 0;
    while(iCur < number)
    {
        if (arr[iCur] != value)
        {
            arr[iToDelete] = arr[iCur];
            iToDelete++;
        }
        iCur++;
    }
    return iToDelete;
}

int main()
{
    const int MAX = 50;
    int arr[MAX];
    int number;
    cin >> number;
    inputArray(arr, number);
    printArray(arr, number);
    number = removeElement(arr, number, 3);
    printArray(arr, number);
    return 0;
}