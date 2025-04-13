#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

// Constant for array size
const int SIZE = 5000;

vector<int> generateReverseSortedArray(int size) {
    vector<int> arr(size);
    // Fill array in reverse-sorted order (e.g., 5000, 4999, ..., 1)
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
    return arr;
}

// Bubble Sort implementation
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swapping occurred, array is sorted
        if (!swapped) break;
    }
}

// Helper function for Quick Sort to partition the array
int partition(vector<int>& arr, int low, int high) {
    // Choose rightmost element as pivot
    int pivot = arr[high];
    // Index of smaller element
    int i = low - 1;

    // Compare each element with pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot's position
}

// Quick Sort implementation
void quickSort(vector<int>& arr, int low, int high) {
    // Base case: if low < high
    if (low < high) {
        // Get partition index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Generate random array
    vector<int> original = generateReverseSortedArray(SIZE);
    // Create copies for sorting
    vector<int> arr1 = original;
    vector<int> arr2 = original;

    // ---- Bubble Sort Timing ----
    // Record start time
    auto start = high_resolution_clock::now();
    bubbleSort(arr1);
    // Record end time
    auto end = high_resolution_clock::now();
    // Calculate duration in milliseconds
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "Bubble Sort Time: " << duration1.count() << " ms" << endl;

    // ---- Quick Sort Timing ----
    // Record start time
    start = high_resolution_clock::now();
    quickSort(arr2, 0, arr2.size() - 1);
    // Record end time
    end = high_resolution_clock::now();
    // Calculate duration in milliseconds
    auto duration2 = duration_cast<milliseconds>(end - start);
    cout << "Quick Sort Time: " << duration2.count() << " ms" << endl;

    return 0;
}