//Recursive Cse - O(2^n)
#include<iostream>
using namespace std;

//Recursive
/* 
                   5
                /      \
               4        3
             /   \      / \
            3     2    2   1
           / \   / \  / \
          2   1  1  0 1  0

*/
int fib(int n)
{
    //Base case 
    if(n==0 or n==1) return n;

    //else
    int ans;
    ans = fib(n-1)+fib(n-2);

    return ans;
}

//Top Down Approach(Recursion + Memoization)
/*  
                5
               / \    dp{0,1,1,2,3,5}
              4   3  idx 0 1 2 3 4 5
             / \     
            3   2   
           / \   
          2   1  
         / \
        1   0

        starig from top and traversing down and storing result in dp array
*/
int fibo(int n,int dp[])
{
    //base case
    if(n==0 or n==1)
    {
        return n;
    }

    //Look Up if the value of number recursively called if present or not
    if(dp[n]!=0)//exists
    {
        return dp[n];
    }

    int ans;
    ans = fibo(n-1, dp) + fibo(n-2, dp);

    return dp[n] = ans;//store value at index
}

//Bottom Up Approach
int fibBU(int n)
{
    //here we will make a dp array
    //and initialise 0th and 1st index as 0 and 1
    //Now next index value we know can be dp[i] = dp[i-1] + dp[i-2]
    int dp[100]={0};
    dp[1]=1;

    //Note: here we are storing an entire array which consumes space O(N)
    //as we can we for computing fibonacci we need to store previous two nos only.
    //So space can be optimised to O(1).
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

//Space optimised bottom up Approach
//storing only previous two values
int fibSpace(int n)
{
    //base case
    if(n==0 or n==1)
    {
        return n;
    }

    long long int a=0; //first fibonacci value
    long long int b=1; //second fibonacci value
    long long int c;

    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    int dp[100]={0};

    // cout<<fibBU(n);
    cout<<fibSpace(n);
    // cout<<fib(n);
    return 0;
}