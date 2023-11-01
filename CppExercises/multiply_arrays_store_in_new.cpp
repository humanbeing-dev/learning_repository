#include <iostream>

using namespace std;

void print(const int *const array, size_t array_size);
int * apply_all(const int *const array1, size_t array_size1, const int *const array2, size_t array_size2);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: ";
    print(array1,array1_size);
    
    cout << "Array 2: ";
    print(array2,array2_size);
    
    int *results = apply_all(&array1[0], array1_size, &array2[0], array2_size);
    constexpr size_t results_size {array1_size * array2_size};
    
    cout << "Result: ";
    print(results,results_size);
    
    delete [] results;
    
    cout << endl;
    
    return 0;   
}

void print(const int *const array, size_t array_size) {
    cout << "[ ";
    for (size_t i{0}; i < array_size; i++)
        cout << array[i] << " ";
    cout << "]";
    cout << endl;
}

int * apply_all(const int *const array1, size_t array_size1, const int *const array2, size_t array_size2){
    
    int *pointer = nullptr;
    pointer = new int[array_size1 * array_size2];
    size_t i = {0};

        for (size_t j = {}; j < array_size2; j++) {
            for (size_t k = {}; k < array_size1; k++){
                pointer[i] = array2[j] * array1[k];
                i++;
            }
        }
    
    return pointer;
}
