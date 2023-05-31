#include <iostream>

using namespace std;

void reverse_array(int* arr, int size);

int main()
{
    int arr[] = {1, 2, 3, 4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i{0}; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    reverse_array(arr, size);
    
    for (int i{0}; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}

void reverse_array(int* arr, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--){
        int *ptr1 = &arr[i];
        int *ptr2 = &arr[j];
        *ptr1 = *ptr1 + *ptr2;
        *ptr2 = *ptr1 - *ptr2;
        *ptr1 = *ptr1 - *ptr2;
    }

}