#include<bits/stdc++.h>
using namespace std;

void max_B_Sum(int *a, int n)
{
    /*Checking for terms where a[i]+i is completely div by 2 and if yes then if i is divisible by 2 then even case else odd
    Also note that anything%2 gives either 0 or 1. So, new array,i.e, B array will contain only 1(odd) and 0's(even). Thus, max B sum will be 
    total arr size - no. of zeros.
    */
    int even = 0, odd = 0;
    for (int i = 1; i <= n;i++)
    {
        if((a[i]+i) & 1)
        {
            continue;
        }
        else
        {
            //Check if I is odd or even
            if(i&1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
    }
    int result = 0;
    result = abs(odd - even); //Exclude 0's from 1's
    result = n - result;      //case when both sum and i is odd;
    cout<<result<<endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 1; i <= n;i++)
        {
            cin >> arr[i];
        }
        max_B_Sum(arr, n);
    }
    return 0;
}