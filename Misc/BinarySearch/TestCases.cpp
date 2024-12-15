#include <iostream>
#include "BinarySearch.h"

int main(){
    int* arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Search soln;
    int pos = soln.binarySearch(arr, 0, 9, 4);
    std::cout << arr[pos] << std::endl;
    delete[] arr;
    return 0;
}