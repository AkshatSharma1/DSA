#include<bits/stdc++.h>
using namespace std;

int modifyBit(int *arr, int p, int b)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n;i++)
    {
        int mask = 1 << p;
        return ((arr[i] & ~mask) | (b << p));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int k1 = 1;
        int k2 = 2;
        int k3 = 3;
        int k4 = 4;
        int val1 = 0;
        int val2 = 0;
        int val3 = 0;
        int val4 = 0;
        int ans = 0;
        int cal_sum = 0;
        string s="";

        long long int arr[n];

        for (int i = 0; i < n;i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n;i++)
        {
            val1 ^= ((arr[i] & (1 << (k1 - 1))) >> (k1 - 1));
            val2 ^= ((arr[i] & (1 << (k2 - 1))) >> (k2 - 1));
            val3 ^= ((arr[i] & (1 << (k3 - 1))) >> (k3 - 1));
            val4 ^= ((arr[i] & (1 << (k4 - 1))) >> (k4 - 1));
        }

        for (int i = 0; i < n - 1;i+=2)
        {
            cal_sum += pow((arr[i] - arr[i + 1]), 2);
        }

        if(cal_sum==0 and arr[n-1]==0)
        {
            cout <<"0"<< endl;
        }
        else if(cal_sum==0)
        {
            cout << "-1" << endl;
        }

        s = s + to_string(val4) + to_string(val3) + to_string(val2) + to_string(val1);

        if(val1==1)
        {
            for (int i = 0; i < n;i++)
            {
                modifyBit(arr[i], 1, 1);
            }
                
        }
    }
}