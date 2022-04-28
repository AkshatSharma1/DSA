#include<bits/stdc++.h>
using namespace std;


//Recursive way
int solve(int arr[],int i,int j)
{
    //Terminate condition
    if(i>=j)
        return 0;

    int mn = INT_MAX;

    for (int k = i; k <= j-1;k++)
    {
        int temp_ans;
        temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if(temp_ans<mn)
        {
            mn = temp_ans;
        }
    }
    return mn;
}


//Memoized way

int static dp[1001][1001];

int solveMem(int arr[],int i,int j)
{
    //Terminate condition
    if(i>=j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j-1;k++)
    {
        int temp_ans;
        temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if(temp_ans<mn)
        {
            mn = temp_ans;
        }
    }
    return dp[i][j] = mn;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    //Recursive way
    // cout << "Minimum number of multiplications is "
    //      << solve(arr, 1, n - 1);

    //For memoization
    memset(dp, -1, sizeof(dp));
    cout << "Minimum number of multiplications is: " << solveMem(arr, 1, n - 1);

    return 0;
}