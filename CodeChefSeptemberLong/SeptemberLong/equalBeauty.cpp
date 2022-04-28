#include<bits/stdc++.h>
#define ll long long
 
using namespace std;

 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k, result1 = 0, result2 = 0;
        ll maxi = INT_MAX;
        ll sa1, sa2;

        cin >> n;

        int arr[n];
        for(ll i=0;i<n;i++)
        { 
            cin >> arr[i];
        }

        sort(arr, arr+n);
 
        ll l = 1, r = n - 2;
        if (n == 2)
        {
            //When only two element in arrays, then the array is already beautiful
            cout << 0 << endl;
            continue;
        }

        //When 3 elements in array, then the minimum of [mid-start,end-mid]
        else if (n == 3)
        {
            cout << min(arr[1] - arr[0], arr[2] - arr[1]) << endl;
            continue;
        }

        for(ll i=0;i<n-1;i++)
        {
            result1 += abs(arr[i] - arr[(n - 1) / 2]);
        }

        for (ll j = 1; j < n; j++)
        {
            result2 += abs(arr[j] - arr[((n - 1) / 2)+1]);
        }

        maxi = min(result1, result2);

        for (int i = l; i < r;i++)
        {
            sa1 = arr[n-1] - arr[l];
            sa2 = arr[r] - arr[0];
            maxi = min(maxi, abs(sa2 - sa1));
            if (sa2 < sa1)
                l++;
            else
                r--;
        }
        cout << maxi << endl;
    }
    return 0;
}