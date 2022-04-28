#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;
        int sum = pow(2,n);//required sum
        int sumTillVal = 0;

        vector<int> arr(n+1);

        //Base case
        if(n==1) {
            cout << "1 1" << endl;
        }

        else
        {
            int i;
            for (i = 0; i < n - 1;i++)
            {
                arr[i] = i + 1;
                sumTillVal += arr[i];
            }
            arr[n] = n - 1;
            sumTillVal = sumTillVal + arr[n];

            //Now input last element as total sum - sum till val
            arr[n] = sum - sumTillVal;

            //Print result
            for (auto it = arr.begin(); it != arr.end(); it++)
            {
                cout << *it;
                cout << " ";
            }
            cout << endl;
        }

    }
    return 0;
}