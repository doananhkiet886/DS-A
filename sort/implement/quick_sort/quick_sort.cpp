#include <iostream>
#include "dynamic_array.cpp"
#include <time.h>

using namespace std;

// khi partition xong thì lấy được pivotIndex sau đó đệ quy 2 nửa
// quickSort(array, left, pivotIndex)
// quickSort(array, pivotIndex + 1, right)
template <class T>
int partition1(DynamicArray<T> &array, int left, int right)
{
    int pivot = array.get(left); //chỉ được chọn phần tử đầu làm pivot

    // Tối ưu hơn thì = left + 1
    // Nhưng dòng 53 phải thay < thành <=
    // Thay vậy vì để xét trường hợp leftIndex == rightIndex dịch
    // chuyển leftIndex sang phải làm cho đúng vị trí để chia đôi array và đệ quy tiếp
    int leftIndex = left;
    int rightIndex = right;
    while(leftIndex < rightIndex)
    {
        // Tìm cặp phần tử nghịch thế
        while(array.get(leftIndex) <= pivot)
            leftIndex++;
        while(array.get(rightIndex) > pivot)
            rightIndex--;

        //Hoán đổi vị trí của cặp phầ tử nghịch thế
        if (leftIndex < rightIndex) // Không " = " vì tránh  trường hợp cùng trỏ vào 1 phần tử mà phải swap thì không tối ưu
        {
            int temp = array.get(leftIndex);
            array.set(leftIndex, array.get(rightIndex));
            array.set(rightIndex, temp);
        }
    }

    // Đưa chốt về đúng vị trí
    array.set(left, array.get(rightIndex));
    array.set(rightIndex, pivot);

    // Sau khi partition xong thì tại rightIndex trở về trước là những phần tử <= pivot
    // Phía sau rightIndex là những phần tử  > pivot
    return rightIndex;
}

// khi partition xong thì lấy được pivotIndex sau đó đệ quy 2 nửa
// quickSort(array, left, pivotIndex)
// quickSort(array, pivotIndex + 1, right)
// SỬ DỤNG PARTITION3 NÀY ĐỂ CODE
template <class T>
int partition2(DynamicArray<T> &array, int left, int right)
{
    int pivot = array.get((left + right) / 2); // được phép chọn pivot bất kỳ

    int leftIndex = left;
    int rightIndex = right;
    while(true)
    {
        while(array.get(leftIndex) < pivot)
            leftIndex++;
        while(array.get(rightIndex) > pivot)
            rightIndex--;

        if (leftIndex < rightIndex)
        {
            int temp = array.get(leftIndex);
            array.set(leftIndex, array.get(rightIndex));
            array.set(rightIndex, temp);

            leftIndex++;
            rightIndex--;
        }
        else
        {
            return rightIndex;
        }
    }
}

// Khi partition xong thì lấy được pivotIndex sau đệ quy 2 nửa
// quickSort(array, left, pivotIndex - 1)
// quickSort(array, pivotIndex, right)
template <class T>
int partition3(DynamicArray<T> &array, int left, int right)
{
    int pivot = array.get((left + right) / 2); // được phép chọn pivot bất kỳ

    int leftIndex = left;
    int rightIndex = right;
    while(leftIndex <= rightIndex)
    {
        while(array.get(leftIndex) < pivot) // Không thể  "<=" ,vì trường hợp (7, 5)
            leftIndex++;
        while(array.get(rightIndex) > pivot)
            rightIndex--;

        if (leftIndex <= rightIndex)
        {
            int temp = array.get(leftIndex);
            array.set(leftIndex, array.get(rightIndex));
            array.set(rightIndex, temp);

            leftIndex++;
            rightIndex--;
        }
    }  

    return leftIndex; // Không thể  return right, vì trường hợp (2, 5)
}

template <class T>
void quickSort1(DynamicArray<T> &array, int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition1(array, left, right);

    quickSort1(array, left, pivotIndex - 1);
    quickSort1(array, pivotIndex + 1, right);
}

template <class T>
void quickSort2(DynamicArray<T> &array, int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition2(array, left, right);

    quickSort2(array, left, pivotIndex);
    quickSort2(array, pivotIndex + 1, right);
}

template <class T>
void quickSort3(DynamicArray<T> &array, int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition3(array, left, right);

    quickSort3(array, left, pivotIndex - 1);
    quickSort3(array, pivotIndex, right);
}

template <class T>
void randomArray(DynamicArray<T> &array)
{
    for (int i = 1; i <= 100000000; i++)
    {
        array.add(rand() % 999);
    }
}
int main()
{
    DynamicArray<int> array(100000000);
    randomArray(array);

    clock_t start, end;
    double timeUse;

    start = clock();
    quickSort1(array, 0, array.size - 1);
    end = clock();
    timeUse = double(end - start) / CLOCKS_PER_SEC;
    cout << "1: " << timeUse << endl;

    start = clock();
    quickSort2(array, 0, array.size - 1);
    end = clock();
    timeUse = double(end - start) / CLOCKS_PER_SEC;
    cout << "2: " << timeUse << endl;

    start = clock();
    quickSort3(array, 0, array.size - 1);
    end = clock();
    timeUse = double(end - start) / CLOCKS_PER_SEC;
    cout << "3: " << timeUse << endl;

    return 0;
}