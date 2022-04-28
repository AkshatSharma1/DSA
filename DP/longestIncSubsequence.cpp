#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     //To take input from a file 
//     // #ifndef ONLINE_JUDGE
//     //     freopen("input.txt","r",stdin);
//     //     freopen("output.txt","w",stdout);
//     // #endif

//     int n;
//     cin>>n;

//     int a[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>a[i];
//     }

//     int dp[n];

//     for(int i=0; i<n; i++)
//     {
//         dp[i] = 1;//every element can end at length 1
//         for(int j=0; j<i;j++)
//         {
//             if(a[j]<a[i])
//             {
//                 dp[i] = max(dp[i],dp[j]+1);
//             }
//         }
//     }
//     int list = 0;

//     for(int i=0; i<n; i++)
//     {
//         list = max(list,dp[i]);
//         cout<<dp[i]<<" ";
//     }

//     cout<<"\n"<<list<<endl;

//     return 0;

// }

// int main()
// {
    
//     int n;
//     cin>>n;

//     int a[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>a[i];
//     }

//     int dp[n+1];//as length starts from 0 

//     //now initially fill dp array with values
//     //fill dp[0] with INT_MIN(-1e9)
//     dp[0] = INT_MIN;

//     //fill rest with 1e9
//     for(int i=1; i<n; i++)
//     {
//         dp[i] = INT_MAX;  //thus we get dp[] = {-1e9,1e9,1e9-------,1e9}
        
//     }

//     //then make comparison according to if statement and place the element in correct position
//     for(int i=0; i<n; i++)
//     {
//         for(int length=0;length<n;length++)
//         {
//             //here as dp array should be strictly increasing, so dp[length+1]>dp[length]
//             if(dp[length] < a[i] and dp[length+1] > a[i])//i.e. dp[length]<a[i]<dp[length+1]
//             { 
//                 dp[length + 1] = a[i];
//             }
//         }
//     }

//     int count = 0;

//     for(int i=0; i<n; i++)
//     {
//         if(dp[i]!=INT_MAX)
//         {
//             count = i;
//         }
//     }
//     cout<<count;

//     return 0;
// }

//using binary search
int main()
{
    
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int dp[n+1];//as length starts from 0 

    //now initially fill dp array with values
    //fill dp[0] with INT_MIN(-1e9)
    dp[0] = INT_MIN;

    //fill rest with 1e9
    for(int i=1; i<n; i++)
    {
        dp[i] = INT_MAX;  //thus we get dp[] = {-1e9,1e9,1e9-------,1e9}
        
    }

    //then make comparison according to if statement and place the element in correct position
    for(int i=0; i<n; i++)
    {
        int length = upper_bound(dp,dp+n+1,a[i]) - dp; //gives index when we did -dp
        if(dp[length-1]<a[i] and dp[length]>a[i])
        {
            dp[length] = a[i];
        }
    }

    int lis = 0;

    for(int i=1; i<=n; i++)
    {
        if(dp[i]!=INT_MAX)
        {
            lis = i;
        }
    }
    cout<<lis;

    return 0;
}