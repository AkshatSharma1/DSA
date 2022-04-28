#include <bits/stdc++.h>
using namespace std;
int  trap(vector<int> &arr)
{
    //move
    int i = 0, j = arr.size() - 1;
    while (arr[j - 1] >= arr[j])
    {
        j--;
    }
    
    int currVal = arr[i], waterUnits = 0, lastMaxVal = arr[i];
    i++;
    int bigIdx;
    while (i <= j)
    {
        currVal = arr[i];
        if (currVal <= lastMaxVal)
        {
            waterUnits += (lastMaxVal - currVal);
        }
        else
        {
            lastMaxVal = currVal;
            bigIdx = i;
        }
        i++;
    }
    if(arr[j]<lastMaxVal){
        while(bigIdx<j){
            if(arr[bigIdx]>arr[j]){
                waterUnits = waterUnits - (j-bigIdx);
            }
            bigIdx++;
        }
        
    }
    return waterUnits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    cout<<trap(arr);
}