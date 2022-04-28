#include<bits/stdc++.h>
using namespace std;

void checkYes(int* arr,int d,int e)
{
    if(arr[0]<=e and arr[1]+arr[2]<=d)
    {
        cout << "Yes"<<endl;
    }
    else
    {
        cout << "No"<<endl;
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int arr[3],d,e;
        for (int i = 0; i < 3;i++) {
            cin >> arr[i];
        }
        cin >> d >> e;
        sort(arr, arr + 3);
        checkYes(arr, d, e);
    }
    return 0;
}