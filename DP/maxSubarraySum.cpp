#include<iostream>
using namespace std;
 
int maxSubArraySumSpaceOptimised(int a[], int size)//Kadane's
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int maxSubArraySum(int a[],int n)
{
    int dp[100]={0};
    dp[0] = a[0]>0?a[0]:0;

    int max_so_far = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i-1] + a[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }

        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySumSpaceOptimised(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}