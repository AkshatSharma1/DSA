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
        int ans = 0;

        int arr[n];
        for (int i = 0; i < n;i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n;i++)
        {
            for (int j = i+1; j < n;j++)
            {
                    if(j-i>=2)
                    {
                        int k = j-1;
                        int c = arr[i] - arr[k];
                        int d = arr[k] - arr[j];
                        ans += (c * d);
                    }

            }
        }
        cout << ans << endl;
    }
    return 0;
}