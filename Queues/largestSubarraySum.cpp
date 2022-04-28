// //Variable sliding window

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the size of the array:"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of the array:"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int k;
//     cout<<"Enter the sum whose longest subarray you want to find:"<<endl;
//     cin>>k;
//     int i=0,j=0,sum=0;
//     int mx=0;
//     deque<int> l;
//     while(j<n)
//     {
//         sum=sum+arr[j];
//         l.push_back(arr[j]);
//         if(sum<k)
//         {
//             j++;
//         }
//         else if(sum==k)
//         {
//             mx=max(mx,j-i+1);
//             j++;
//         }
//         else
//         {
//             while(sum>k)
//             {
//                 sum=sum-arr[i];
//                 i++;
//                 l.pop_front();
//             }
//             j++;
//         }
//     }
//     cout<<mx<<endl;
//     return 0;
// }

#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to find the maximum length subarray with sum `S` present
// in a given array
void findMaxLenSubarray(int arr[], int n, int S)
{
    // create an empty map to store the ending index of the first subarray
    // having some sum
    unordered_map<int, int> map;
 
    // insert `(0, -1)` pair into the set to handle the case when a
    // subarray with sum `S` starts from index 0
    map[0] = -1;
 
    int sum = 0;
 
    // `len` stores the maximum length of subarray with sum `S`
    int len = 0;
 
    // stores ending index of the maximum length subarray having sum `S`
    int ending_index = -1;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        sum += arr[i];
 
        // if the sum is seen for the first time, insert the sum with its
        // into the map
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
 
        // update length and ending index of the maximum length subarray
        // having sum `S`
        if (map.find(sum - S) != map.end() && len < i - map[sum - S])
        {
            len = i - map[sum - S];
            ending_index = i;
        }
    }
 
    // print the subarray index
    cout << "[" << (ending_index - len + 1) << "," << ending_index << "]"<<endl;
    cout<<"[ ";
    for(int i=ending_index-len+1; i<=ending_index; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"]";
}
 
int main()
{
    int arr[] = {4,1,1,1,2,3,5};
    int sum = 5;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    findMaxLenSubarray(arr, n, sum);
 
    return 0;
}


