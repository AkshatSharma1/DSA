#include<iostream>
using namespace std;

int subset(int *arr,int sum,int n)
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
        for (int j = 0; j < sum + 1;j++)
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
    int sum = 3;

    cout << "Subsets with given sum are: " << subset(arr, sum, n);

    return 0;
}