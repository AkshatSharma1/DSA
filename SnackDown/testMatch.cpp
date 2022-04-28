#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int arr[5];
        int countIndia = 0, countEngland = 0;

        for(int i = 0; i < 5; i++) {
            cin>>arr[i];
            if(arr[i]==1) countIndia++;
            else if(arr[i]==2) countEngland++;
        }

        if(countIndia>countEngland)
            cout << "INDIA" << endl;
        else if (countEngland > countIndia)
                cout<< "ENGLAND" << endl;
        else
            cout << "DRAW"<<endl;
    }
    return 0;
}