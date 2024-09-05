/*

Author: Shamik V. Patro

The stable counting sort algorithm requires the preservation of position for duplicate elements in an array.
Stability is a vital property for extensions of the counting sort algorithm (i.e. Radix Sort).

*/

#include <iostream>

int* findFrequencies(int* arr, int size, int* freq){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; j++){
            if (i == arr[j]){
                freq[arr[j]]++;
            }
        }
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

int* arrange(int* arr, int* acc_freq, int size, int* sorted){
    for (int i = size-1; i >= 0; i--){
        acc_freq[arr[i]]--;
        int pos = acc_freq[arr[i]];
        sorted[pos] = arr[i];
    }

    return sorted;
}

int main(){

    int size = 15;
    int* arr = new int[size]{1, 6, 3, 7, 8, 2, 9, 5, 4, 0, 7, 7, 7, 7, 5};
    int* freq = new int[size]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int* acc_freq = new int[size];
    int* sorted = new int[size]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

    acc_freq = addFrequencies(freq, size);
    //acc_freq = shiftArray(freq, size);

    std::cout << "[ ";

    for (int i = 0; i < size; i++){
	    std::cout << i << " ";
    }

    std::cout << "]";
    std::cout << std::endl;
    std::cout << "[ ";

    for (int i = 0; i < size; i++){
	    std::cout << acc_freq[i] << " ";
    }

    std::cout << "]";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Here is the sorted array:" << std::endl;

    sorted = arrange(arr, acc_freq, size, sorted);

    std::cout << "[ ";
    for (int i = 0; i < size; i++){
        std::cout << sorted[i] << " ";
    }
    std::cout << "]";
    std::cout << std::endl;

    //delete [] sorted;
    //delete [] acc_freq;
    //delete [] freq;
    //delete [] arr;

return 0;

}
