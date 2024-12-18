#pragma once
#include <iostream>
class Search{
    public:
        int binarySearch(int* arr, int left, int right, int key){
            if (right >= left){
                int mid = left + (right - left) / 2;
                if (arr[mid] == key){
                    return mid;
                }
                if (key < arr[mid]){
                    return binarySearch(arr, left, mid - 1, key);
                }
                return binarySearch(arr, mid+1, right, key);
            }
        return -1;
    }
};