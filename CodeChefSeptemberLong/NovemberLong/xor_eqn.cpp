#include<bits/stdc++.h>
using namespace std;

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

        long long int arr[n];

        int cal_sum = 0;
        int x=0;

        for (int i = 0; i < n;i++)
        {
            cin >> arr[i];
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

        else
        {
            x = -(2 * (cal_sum - arr[n - 1])) / 2;

            if(x>=0)
            {
                cout << x << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
    }
     return 0;
}