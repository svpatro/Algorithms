/*

Author: Shamik V. Patro

Counting Sort Algorithm Functions:

findFrequencies: Tracks the occurances of each element in the original array by assigning it to a frequency array.
addFrequencies: Adds the frequencies of the frequency array in increasing order.
shiftArray: Takes the frequency array and shifts it one index right.
arrange: Uses the shifted frequency array to arrange the elements of the original array.

*/

#include <iostream>

int* findFrequencies(int* arr, int size, int* freq){
    for (int i = 0; i < size; ++i){
        int count = 0;
        for (int j = 0; j < size; j++){
            if (i == arr[j]){
                count++;
            }
        }
        freq[i] = count;
    }
    return freq;
}

int* addFrequencies(int* arr, int size){
	for (int i = 1; i < size; i++){
		arr[i] = arr[i] + arr[i-1];
	}
	return arr;
}

int* shiftArray(int* arr, int size){
    for (int i = size-1; i >= 0; i--){
        arr[i] = arr[i-1];
    }
    return arr;
}

int* arrange(int* freq, int size, int* sorted){
    for (int i = 0; i < size-1; i++){
        for (int j = freq[i]; j < freq[i+1]; j++){
            sorted[j] = i;
        }
    }
    return sorted;
}

int main(){

    int size = 15;
    int* arr = new int[size]{1, 6, 3, 7, 8, 2, 9, 5, 4, 0, 7, 7, 7, 7, 5};
    int* freq = new int[size];
    int* sorted = new int[size];

    std::cout << "This is the original array:" << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < size; i++){
	    std::cout << arr[i] << " "; 
    }
    std::cout << "]";

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "These are the frequencies of each number:" << std::endl;

    freq = findFrequencies(arr, size, freq);

    std::cout << "[ ";
    for  (int i = 0; i < size; i++){
	    std::cout << i << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < size; i++){
        std::cout << freq[i] << " ";
    }
    std::cout << "]";

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "These are the new indices of each number:" << std::endl;

    freq = addFrequencies(freq, size);
    freq = shiftArray(freq, size);

    std::cout << "[ ";

    for (int i = 0; i < size; i++){
	    std::cout << i << " ";
    }

    std::cout << "]";
    std::cout << std::endl;
    std::cout << "[ ";

    for (int i = 0; i < size; i++){
	    std::cout << freq[i] << " ";
    }

    std::cout << "]";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Here is the sorted array:" << std::endl;

    sorted = arrange(freq, size, sorted);

    std::cout << "[ ";
    for (int i = 0; i < size; i++){
        std::cout << sorted[i] << " ";
    }
    std::cout << "]";
    std::cout << std::endl;

    delete [] arr;
    delete [] freq;
    delete [] sorted;

return 0;

}
