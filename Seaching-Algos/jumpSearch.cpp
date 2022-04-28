//Complexity Time b/w linear Search and Binary Search
//STEP SIZE, m = sqrt(n);
#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch(int *arr,int n,int key){
    //Jump sqrt(n) steps each iteration till the no >= key. When no.>=key go behind one iteration jump and do linear search

    int step = sqrt(n);

    //Store prev in case no>=key
    int prev = 0;
    while(arr[min(step,n) - 1] < key){
        prev = step;
        step += sqrt(n);
        if(prev>=n){
            return -1;
        }
    }

    //When no>=key go behind one iteration jump and do linear search
    while(arr[prev] < key){
        prev++;//linear search
        if(prev == min(step,n))
            return -1;
        if(arr[prev] == key)
            return prev;
    }
    return -1;
}

int main(){
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int key;
    cin >> key;
    int length = sizeof(arr)/sizeof(arr[0]);

    int ans = jumpSearch(arr, length, key);

    ans == -1 ? cout << "fasle" : cout << "True";
    return 0;
}