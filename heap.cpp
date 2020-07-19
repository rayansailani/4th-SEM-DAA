// C++ program for implementation of Heap Sort
#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[100];
    int n;
    clock_t t;
    cout << "*HEAP SORT*" << endl;
    cout << "Enter the number of elements to be sorted: " << endl;
    cin >> n;
    cout << "Enter the elements of the array to be sorted: " << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    cout << "The given array is: " << endl;
    printArray(arr, n);
    t = clock();
    heapSort(arr, n);
    t = clock() - t;
    cout << "Sorted array is \n";

    printArray(arr, n);
    cout << "time taken: " << ((float)t) / CLOCKS_PER_SEC << "seconds" << endl;
}