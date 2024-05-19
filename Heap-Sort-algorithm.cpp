// Ankit Vishwakarma 
#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in an array
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// Function to heapify a subtree rooted at index 'i'
// n is size of heap
void heapify(vector<int>& arr, int n, int i) {
  int largest = i; // Initialize largest as root
  int left = 2 * i + 1; // left = 2*i + 1 (0-based indexing)
  int right = 2 * i + 2; // right = 2*i + 2 (0-based indexing)

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to build a max heap (rearrange array)
void buildHeap(vector<int>& arr, int n) {
  // Start from last non-leaf node and heapify all child nodes
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

// Function to sort an array using Heap Sort
void heapSort(vector<int>& arr, int n) {
  // Build heap (rearrange array)
  buildHeap(arr, n);

  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    swap(arr[0], arr[i]);

    // Call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// Function to print the array
void printArray(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  int n = arr.size();

  cout << "Unsorted array: ";
  printArray(arr);

  heapSort(arr, n);

  cout << "Sorted array using Heap Sort: ";
  printArray(arr);

  return 0;
}
