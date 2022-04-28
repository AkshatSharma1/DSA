#include<iostream>
using namespace std;

int binarySearch(int* arr,int start,int end,int key)
{
    if(end>=start){
        int mid = start + (end - start) / 2;

        //Check if mid = key
        if(arr[mid] == key)
        {
            return mid;
        }

        if(arr[mid] > key){
            return binarySearch(arr, start, mid - 1, key);
        }

        if(arr[mid] < key){
            return binarySearch(arr, mid + 1, end, key);
        }
    }
    //If key not found
    return -1;
}

int exponentialSearch(int *arr,int n,int key)
{
    if(arr[0]==key)
        return 0;
    
    //Find range
    int i = 1;
    while (i < n and arr[i<=key])
    {
        i = i * 2;

        return binarySearch(arr, i / 2, min(i, n - 1), key);
    }
}

int main()
{
    int arr[] = {10, 20, 50, 90, 64, 14, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 50;

    cout << "element found at index "<<exponentialSearch(arr, n, key);
}
