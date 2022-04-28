#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int flag = 0;
    while(t--) {
        int arr[3];
        for(int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < 3; i++)
        {
            if(arr[i] == 7)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }

        if(flag==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}