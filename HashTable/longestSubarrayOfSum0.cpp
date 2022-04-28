#include<bits/stdc++.h>
using namespace std;

int maxLength(int* arr,int n)
{
    unordered_map<int,int> m;
    int maxLen = INT_MIN;
    int curr_sum = 0;

    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(arr[i] == 0 and maxLen == 0)
        {
            maxLen = 1;
        }

        if(curr_sum==0)
        {
            maxLen = i+1;
        }

        else
        {
            if(m[curr_sum])//if exists already
            {
                maxLen = max(maxLen,i-m[curr_sum]);//i - prev same sum indx  
            }
            else
            {
                m[curr_sum] = i; //if donot exist
            }
        }
    }
    return maxLen;
}

int main(){
    int arr[] = {1,-1,3,2,-2,-8,1,7,10,23};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max length subarray of sum 0 is: "<<maxLength(arr,n)<<endl;

    return 0;
}