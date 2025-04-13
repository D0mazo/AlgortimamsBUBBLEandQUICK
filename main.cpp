#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 5000;

// ---- Bubble Sort ----
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ---- Quick Sort ----
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---- Helper ----
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int& x : arr)
        x = rand() % 10000;
    return arr;
}

int main() {
    srand(time(0));
    vector<int> original = generateRandomArray(SIZE);
    vector<int> arr1 = original;
    vector<int> arr2 = original;

    // ---- Bubble Sort Timing ----
    auto start = high_resolution_clock::now();
    bubbleSort(arr1);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "Bubble Sort Time: " << duration1.count() << " ms" << endl;

    // ---- Quick Sort Timing ----
    start = high_resolution_clock::now();
    quickSort(arr2, 0, arr2.size() - 1);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);
    cout << "Quick Sort Time: " << duration2.count() << " µs" << endl;

    return 0;
}
