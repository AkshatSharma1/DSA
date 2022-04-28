//Similar to count of subsets equal to given sum
#include<bits/stdc++.h>
using namespace std;

int subsetWithGivenDiff(int *arr,int n,int sum)
{
    //Make a dp matrix
    int dp[n + 1][sum + 1];

    //initialise it
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }

    //Now fill the rest dp matrix
    for (int i = 1; i < n + 1;i++)
    {
        for (int j = 1; j < sum + 1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    //Weight and value array
    int arr[] = {1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;
    //Find sum of array values
    int sum = accumulate(arr, arr + n, 0);

    int tar_sum = (sum + target) / 2;

    cout << "Subsets with given diff are: " << subsetWithGivenDiff(arr, n,tar_sum);

    return 0;
}