#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

// Function to reverse a string in-place
void reverseString(string& str) {
    int n = str.length();
    // Efficiently reverse using two-pointer approach
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    // Handle empty or single-element arrays
    if (size <= 1) {
        return;
    }

    // Efficiently reverse using two-pointer approach
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}

// Function to concatenate two strings (using string operator+)
string concatenateStrings(string str1, string str2) {
    return str1 + str2;
}

int main() {
    // String reversal
    string str = "Hello, world!";
    cout << "Original string: " << str << endl;
    reverseString(str);
    cout << "Reversed string: " << str << endl; // !dlrow ,olleH

    // Array reversal
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); // Get array size
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    reverseArray(arr, size);
    cout << "Reversed array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl; // [5 4 3 2 1]

    // String concatenation
    string strA = "This is ";
    string strB = "a string.";
    string combined = concatenateStrings(strA, strB);
    cout << "Concatenated string: " << combined << endl; // This is a string.

    return 0;
}
