#include <iostream>
using namespace std;

void enterArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 999;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // n - 1 = 2i + 1 => n = 2i + 2 => i = (n - 2) / 2 = n/2 - 1
    // n - 1 = 2i + 2 => n = 2i + 3 => i = (n - 3) / 2 = n/2 - 3/2 = n/2 - 1 (làm tròn 3/2 xuống)
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int curN = n-1; curN >= 0; curN--)
    {
        swap(arr[0], arr[curN]);
        heapify(arr, curN, 0);
    }
}
int main()
{
    srand(time(NULL));
    const int n = 1000000;
    int arr[n];
    enterArray(arr, n);
    printArray(arr, n);
    cout << endl;

    heapSort(arr, n);
    printArray(arr, n);
    cout << endl;
    return 0;
}