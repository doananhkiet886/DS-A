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

void merge2SortedArray(int dest[], int &numberDest, int source[], int numberSource)
{
    int iRightDest = numberDest - 1;
    int iRightSource = numberSource - 1;
    int iRightResult = (numberDest + numberSource) - 1;

    while (iRightResult >= 0)
    {
        if (iRightDest < 0)
        {
            dest[iRightResult] = source[iRightSource];
            iRightSource--; 
        }
        else if (iRightSource < 0)
        {
            dest[iRightResult] = dest[iRightDest];
            iRightDest--;
        }
        else if (dest[iRightDest] > source[iRightSource])
        {
            dest[iRightResult] = dest[iRightDest];
            iRightDest--;
        }
        else if (dest[iRightDest] <= source[iRightSource])
        {
            dest[iRightResult] = source[iRightSource];
            iRightSource--;
        }

        iRightResult--;
    }

    numberDest = numberDest + numberSource;
}


int main()
{
    const int MAX = 50;
    int arr1[MAX];
    int arr2[MAX];
    int number1, number2;
    cin >> number1 >> number2;
    inputArray(arr1, number1);
    inputArray(arr2, number2);
    cout << "\t\tTWO ARRAY\n";
    printArray(arr1, number1);
    printArray(arr2, number2);
    
    merge2SortedArray(arr1, number1, arr2, number2);
    cout << "\t\tMERGED ARRAY 1\n";
    printArray(arr1, number1);
    return 0;
}