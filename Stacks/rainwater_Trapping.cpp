#include<iostream>
#include<vector>
using namespace std;

int waterTrapped(int arr[],int n)
{

    int mxl[n],mxr[n];

    //Initialise smallest element as per ascending sort order
    mxl[0] = arr[0];
    //finding max element in the left of arr[i]
    for(int i=1;i<n;i++)
    {
        mxl[i] = max(mxl[i-1],arr[i]);
    }

    //Initialise largest element as per ascending order
    mxr[n-1] = arr[n-1];
    //finding max element in the right of arr[i]
    for(int i=n;i>0;i--)
    {
        mxr[i] = max(mxr[i+1],arr[i]);
    }

    // int water[i];
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum = sum + (min(mxl[i],mxr[i]) - arr[i]); // sum+water[i]
    }

    return sum;
}

int main()
{
    int s[] = {3,0,0,2,0,4};
    int n = sizeof(s) / sizeof(s[0]);

    cout<<waterTrapped(s,n);

    return 0;
}