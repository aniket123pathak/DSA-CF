#include <iostream>
#include <iomanip> // For setprecision

using namespace std;

// Define a maximum size for the arrays
const int MAX_SIZE = 30;

// --- Utility Functions ---

void displayArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "% ";
    }
    cout << endl;
}

void displayTopFive(float arr[], int n) {
    if (n == 0) {
        cout << "No scores to display." << endl;
        return;
    }
    
    cout << "Top 5 Scores (Highest to Lowest):" << endl;
    
    int count = 0;
    for (int i = n - 1; i >= 0 && count < 5; i--) {
        cout << (count + 1) << ". " << arr[i] << "%" << endl;
        count++;
    }
    
    if (n < 5) {
        cout << "(Only " << n << " scores were entered)" << endl;
    }
}

// --- a) Merge Sort Implementation ---

// Merge function for Merge Sort
void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // --- FIX IS HERE ---
    // We MUST use dynamic allocation here because n1 and n2 are
    // calculated at runtime and are not constant values.
    float* L = new float[n1];
    float* R = new float[n2];
    // --- END FIX ---

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; 
    int j = 0; 
    int k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { 
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // --- FIX IS HERE ---
    // Clean up the dynamically allocated temporary arrays
    delete[] L;
    delete[] R;
    // --- END FIX ---
}

// Main Merge Sort function (recursive)
void mergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- b) Bubble Sort Implementation ---

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

// --- Main Program ---

int main() {
    float percentages[MAX_SIZE];
    float bubbleSortCopy[MAX_SIZE];
    float mergeSortCopy[MAX_SIZE];

    int n; 
    cout << "Enter the number of students (max " << MAX_SIZE << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid number. Please enter a value between 1 and " << MAX_SIZE << "." << endl;
        return 1; 
    }

    cout << "Enter " << n << " student percentages (e.g., 85.5):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
        bubbleSortCopy[i] = percentages[i];
        mergeSortCopy[i] = percentages[i];
    }

    cout << fixed << setprecision(2);

    cout << "\nOriginal Array: ";
    displayArray(percentages, n);

    // --- 1. Sort using Bubble Sort ---
    bubbleSort(bubbleSortCopy, n);
    cout << "\nSorted with Bubble Sort (Ascending): ";
    displayArray(bubbleSortCopy, n);

    // --- 2. Sort using Merge Sort ---
    mergeSort(mergeSortCopy, 0, n - 1);
    cout << "\nSorted with Merge Sort (Ascending): ";
    displayArray(mergeSortCopy, n);

    // --- 3. Display Top 5 Scores ---
    cout << "\n----------------------------" << endl;
    displayTopFive(mergeSortCopy, n);
    cout << "----------------------------" << endl;

    return 0;
}