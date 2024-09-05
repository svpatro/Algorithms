/*

Mergesort is ultimately a divide-and-conquer algorithm.
Given an array, split the array into subarrays and subsubarrays. 
Sort the subsubarrays and merge into subarrays. 
Merge subarrays into original array.
Time complexity is O(nlogn) in the worst case.

*/

#include <iostream>

int* merge(int* arr, int s, int m, int e){


    return arr;
}

int* mergeSort(int* arr, int s, int e){

    // Divide until you cannot divide anymore

    std::cout << std::endl;
    for (int i = s; i < e; i++){
        std::cout << arr[i] << " ";
    }    

    if (s >= e){ 
        return arr;
     }

    int m = s + (e - s) / 2;
    
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, m, e);

    return arr;
}



int main(){

    int size = 10;
    int start = 0;
    int end = 9;
    int mid = end/2;
    int* arr = new int[10]{7, 4, 9, 2, 1, 3, 6, 8, 5, 0};

    arr = mergeSort(arr, start, end);

    for (int i = 0; i < end; i++){

        std::cout << arr[i] << " ";

    };

    return 0;
}