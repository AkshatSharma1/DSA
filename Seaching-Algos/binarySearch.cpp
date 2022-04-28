#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr,int start,int end,int key)
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

int main()
{
    int n;
    cin >> n;
    int key;
    cin >> key;

    vector<int> v;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    int ans = binarySearch(v,0, v.size() - 1, key);

    ans == -1 ? cout << "False" : cout << "True";

    return 0;
}