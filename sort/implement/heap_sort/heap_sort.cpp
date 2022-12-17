#include <iostream>
using namespace std;

void enterArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 99;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) // có hoán đổi chỉ số
    {
        swap(array[i], array[largest]);
        
        heapify(array, n, largest);
    }
}

/*
    Quy ước:
    left node: 2*i + 1 (i la index node cha)
    right node: 2*i + 2 (i la index node cha)
    parent node: (child - 1) / 2 (child la index node con)
    last parent node: sizeArray/2 - 1
*/

// 1. Tạo thành max heap (xuất phát từ node cha cuối cùng (index = n / 2 - 1) trở về  trước)
// 2. Swap phần tử đầu với phần tử cuối
// 3. Loại bỏ phần tử cuối ra khỏi heap
// 4. Heapify tại root (index = 0) với số lượng n - 1 phần tử đã giảm đi ở bước 3
// 5. Lặp lại từ bước 2 -> 4 cho tới khi số lượng phần tử để heapify = 0 thì dừng
void heapSort(int array[], int n)
{
    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    // heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main()
{
    srand(time(NULL));
    const int n = 10;
    int array[n];
    enterArray(array, n);
    printArray(array, n);
    cout << endl;
    heapSort(array, n);
    printArray(array, n);
    cout << endl;
    return 0;
}

