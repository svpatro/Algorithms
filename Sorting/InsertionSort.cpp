#include <iostream>

int* insertionSort(int* arr, int size){

    for (int i = 1; i < size; i++){
        int j = i - 1;
        while (j >= 0 && arr[j+1] < arr[j]){
            int tmp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
    return arr;
}

int main(){

    int size = 5;
    int* arr = new int[size]{2, 6, 1, 3, 0};

    std::cout << "Here is the array unsorted: " << std::endl;

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Here is the array sorted: " << std::endl;

    arr = insertionSort(arr, size);

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}