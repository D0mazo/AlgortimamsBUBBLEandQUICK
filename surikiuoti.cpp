#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

// Function to generate a sorted array of specified size
vector<int> generateSortedArray(int size) {
    vector<int> arr(size);
    // Fill array in sorted order (e.g., 1, 2, ..., size)
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

// Modified Bubble Sort to detect if array is sorted
bool isSortedBubble(vector<int>& arr) {
    int n = arr.size();
    // Perform one pass like Bubble Sort
    for (int j = 0; j < n - 1; j++) {
        // If any adjacent elements are out of order, array is not sorted
        if (arr[j] > arr[j + 1]) {
            return false;
        }
    }
    // If no swaps needed, array is sorted
    return true;
}

// Modified Quick Sort to detect if array is sorted
bool isSortedQuick(vector<int>& arr, int low, int high) {
    // Base case: if subarray has 1 or fewer elements, it's sorted
    if (low >= high) return true;

    // Check if array is already sorted by scanning once
    for (int i = low; i < high; i++) {
        if (arr[i] > arr[i + 1]) {
            return false; // Not sorted
        }
    }
    return true; // Array is sorted
}

int main() {
    // Array of sizes to test
    vector<int> sizes = {5000, 10000, 50000, 100000};

    // Loop through each size
    for (int size : sizes) {
        cout << "\nTesting array size: " << size << endl;

        // Generate sorted array for this size
        vector<int> original = generateSortedArray(size);
        // Create copies for checking
        vector<int> arr1 = original;
        vector<int> arr2 = original;

        // ---- Bubble Sort Detection Timing ----
        auto start = high_resolution_clock::now();
        bool bubbleResult = isSortedBubble(arr1);
        auto end = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(end - start);
        cout << "Bubble Sort Detection Time: " << duration1.count() << " µs" << endl;
        cout << "Bubble Sort Result (is sorted?): " << (bubbleResult ? "Yes" : "No") << endl;

        // ---- Quick Sort Detection Timing ----
        start = high_resolution_clock::now();
        bool quickResult = isSortedQuick(arr2, 0, arr2.size() - 1);
        end = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(end - start);
        cout << "Quick Sort Detection Time: " << duration2.count() << " µs" << endl;
        cout << "Quick Sort Result (is sorted?): " << (quickResult ? "Yes" : "No") << endl;
    }

    return 0;
}