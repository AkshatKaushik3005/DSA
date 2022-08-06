#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++) // equal as starting from 1
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    // Base case
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    // sort left part
    quickSort(arr, s, p - 1);
    // sort right part
    quickSort(arr, p + 1, e); // as pivot is in right place
}
int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
Partition based sorting ... Taking a element(pivot) and fixing it to its right position such that elements to left are smaller and right are bigger
Time Complexity->
Worst Case->O(n^2)
Best & Average CAse->O(nlogn)
Space Complexity->O(n)
*/