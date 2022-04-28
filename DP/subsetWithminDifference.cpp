#include<bits/stdc++.h>
using namespace std;

int subsetMinDiff(int *arr,int n,int range)
{
    //Make a dp matrix
    //or we will make a dp array as we only want the last row of dp matrix

    int tar = (range / 2) + 1;

    bool dp[n+1][tar];
    for (int i = 0; i < n + 1;i++)
    {
        for (int j = 0; j < tar;j++)
        {
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }

    //Fill the matrix
    for (int i = 1; i < n + 1;i++)
    {
        for (int j = 1; j < tar;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    //Make a vector to store last row or do not make it and simply do dp[n][variable]

    int mn = INT_MAX;

    for (int i = range / 2; i >= 0;i--)
    {
        //Find min difference
        if(dp[n][i])
            //use this when iterate from starting
            // mn = min(mn,abs(range - 2 * i));
            mn = range - 2 * i;
            break;
    }
    return mn;
}

int main()
{
    int arr[] = {1,6,11,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = accumulate(arr, arr + n, 0);

    cout << "Min difference between subsets is: " << subsetMinDiff(arr, n, sum);
}