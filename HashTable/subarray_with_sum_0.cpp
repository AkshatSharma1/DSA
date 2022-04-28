//Find if there is a subarray with sum equal to 0

#include<bits/stdc++.h>
using namespace std;

//Method 1: Brute force
void checkZero(int arr[],int n)
{
    int flag = 0;//flag=1 if subarray sum = 0
    int s_indx = 0;
    int e_indx = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                flag=1;
                s_indx = arr[i];
                e_indx = arr[j];
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Yes, a subarray with sum equal to 0 is present and it ranges between [ "<<s_indx<<" , "<<e_indx<<" ]";
    }
    else
    {
        cout<<"No such subarray is present.";
    }
}

//Method 2: Hahsing(unordered_map)
void checkHahsingZero(int arr[],int n)
{
    unordered_map<int,int> m;
    int sum = 0;
    int flag = 0;
    //prefix sum 
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        //if sum = 0 and prefix sum value already exists and arr[i]==0
        if(sum==0 or m[sum] or arr[i]==0) //aliter: m[sum] can be written as using stl s.find(sum)!=s.end
        {
            flag = 1;
            break;
        }
        else
        {
            m[sum]++; //aliter: s.insert(sum)
        }

    }
    if(flag==1)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    int arr[] = {4,2,-3,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    //Method 1:
    // checkZero(arr,n);

    //Method 2: Hahsing
    checkHahsingZero(arr,n);

    return 0; 
}