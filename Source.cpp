#include <iostream>
#include <time.h>
#include <iomanip>
//#include "Sorts2.h"

using namespace std;


void selectionSort(int a[], int size) {
    int outer, inner, min;
    for (outer = 0; outer < size - 1; outer++) {
        min = outer;
        for (inner = outer + 1; inner < size; inner++) {
            if (a[inner] < a[min]) {
                min = inner;
            }
        }
        int temp = a[outer];
        a[outer] = a[min];
        a[min] = temp;
    }
}
///////////////////////////////////////////////
void insertionSort(int nums[], int numSize) {
    int i, j = 0;
    int temp = 0;

    for (int i = 1; i < numSize; i++) {
        j = i;
        while (j > 0 && nums[j] < nums[j - 1]) {
            temp = nums[j];
            nums[j] = nums[j - 1];
            nums[j - 1] = temp;
            --j;
        }
    }
}
///////////////////////////////////////////////
void BubbleSort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

///////////////////////////////////////////////
void Merge(int nums[], int i, int j, int k) {
    int mergedSize = k - i + 1;
    int mergePOS = 0;
    int leftPOS = 0;
    int rightPOS = 0;
    auto mergedNumbers = new int[mergedSize];


    leftPOS = i;
    rightPOS = j + 1;

    while (leftPOS <= j && rightPOS <= k) {
        if (nums[leftPOS] <= nums[rightPOS]) {
            mergedNumbers[mergePOS] = nums[leftPOS];
            ++leftPOS;
        }
        else {
            mergedNumbers[mergePOS] = nums[rightPOS];
            ++rightPOS;
        }
        ++mergePOS;
    }

    while (leftPOS <= j) {
        mergedNumbers[mergePOS] = nums[leftPOS];
        ++leftPOS;
        ++mergePOS;
    }

    while (rightPOS <= k) {
        mergedNumbers[mergePOS] = nums[rightPOS];
        ++rightPOS;
        ++mergePOS;
    }
    for (mergePOS = 0; mergePOS < mergedSize; ++mergePOS) {
        nums[i + mergePOS] = mergedNumbers[mergePOS];
    }
}

void mergeSort(int nums[], int i, int k) {

    int j = 0;

    if (i < k) {
        j = (i + k) / 2;
        mergeSort(nums, i, j);
        mergeSort(nums, j + 1, k);
        Merge(nums, i, j, k);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);

}
///////////////////////////////////////////////


void heapify(int arr[], int x, int i) {

    int largest = i, l, r;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < x && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < x && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, x, largest);
    }
}

void heapSort(int arr[], int x) {
    for (int i = x / 2 - 1; i >= 0; i--) {
        heapify(arr, x, i);

    }
    for (int i = x - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//////////////////////////////////////////////////////

void randArr(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        int n = rand() % num;
        arr[i] = n;
    }
}
void print(int arr[], int sizeOf) {
    for (int i = 0; i < sizeOf - 1; i++) {
        cout << arr[i] << "\n";
        cout << arr[sizeOf];
    }
}


void reset(int arr[], int temp[], int num) {
    for (int i = 0; i < num; i++) {
        arr[i] = temp[i];
    }

}




void Menu() {

    cout << "0. Print the Array with no Sort\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5.Quick Sort\n6.Heap Sort\n7. Exit Program";
}



int main() {
    const int sizeOfArray = 10000;
    int largeArray[sizeOfArray], choice, temp[sizeOfArray];

    randArr(largeArray, sizeOfArray);

    do {
        Menu();
        cout << "\nEnter your method of sorting please" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;

        case 1:
            selectionSort(largeArray, sizeOfArray);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;
            
        case 2:
            insertionSort(largeArray, sizeOfArray);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;

        case 3:
            BubbleSort(largeArray, sizeOfArray);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;

        case 4:
            mergeSort(largeArray, 0, sizeOfArray-1);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;

        case 5:

            quickSort(largeArray, 0, sizeOfArray - 1);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;
        case 6:
           heapSort(largeArray,  sizeOfArray);
            print(largeArray, 50);
            reset(largeArray, temp, sizeOfArray);
            break;
        case 7:
            exit(0);

        default:
            cout << "Invalid choice";
            break;
        }
        return choice;
    } while (choice !=7);
}
