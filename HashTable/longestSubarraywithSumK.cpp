#include<bits/stdc++.h>
using namespace std;

int maxLength(int* arr,int n,int k)
{
    int sum=0;
    int maxLen = INT_MIN;
    unordered_map<int,int> m;

    //find prefix sum
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            maxLen = i+1;
        }
        else
        {
            if(m.find(sum)==m.end())//if prefix sum donot exists
            {
                //insert prefix sum into map
                m[sum] = i;
            }
            
            //now chevk if sum-k present in unordered_map
            if(m.find(sum-k)!=m.end())//if exists 
            {
                maxLen = max(maxLen,i - m[sum-k]);
            }
        }
    }
    return maxLen;
}

int main()
{
    int arr[] = {10,5,2,7,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k; cin>>k;

    cout<<"Max subarray of sum k = "<<k<<" is: "<<maxLength(arr,n,k)<<endl;

    return 0;
}