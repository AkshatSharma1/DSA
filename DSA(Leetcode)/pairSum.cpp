#include<bits/stdc++.h>
using namespace std;

//M-1: Using map
int pairCount(int arr[], int n, int tar){

    //  take a unoredered map
    unordered_map<int,int> mp;
    int count = 0;

    //Now check if for the ith index is there val(tar - ith) in map which means ((tar-ith), ith) is a pair if it is in the map
    for(int i=0;i<n;i++){
        //get the tar-ith val
        int b = tar - arr[i];

        //if exists then it means (b,arr[i]) is a pair thus increase the count and update the freq of arr[i] in map
        if(mp[b]){
            count = count + mp[b];
        }
        //else only increase the count of arr[i]
        mp[arr[i]]++;
    }
    return count;
}

//M-2: Using two pointers and the idea of counting freq of i and j
int pairSum(int arr[], int n, int tar){
    int count = 0;
    sort(arr,arr+1);

    int l = 0, r = n-1;

    while(l<r){
        int curr = arr[l] + arr[r];
        if(arr[l] + arr[r] < tar){
            l++;
        }
        else if(curr>tar){
            r--;
        }
        else{

            //if arr[l] = arr[r]
            if(arr[l]==arr[r]){
                //how many ways are there to select 2 elements out of a range m i.e. mC2
                int range = r-l+1;
                count = count + (range*(range-1))/2;
                break;
            }

            else{
                //store frequencies of arr[i] and arr[j]
                int count_of_left = 1, count_of_right = 1;
                while(l<r and arr[l+1] == arr[r-1]){
                    l++;
                    count_of_left++;
                }
                while(l<r and arr[r-1]==arr[r]){
                    r--;
                    count_of_right++;
                }

                count+=count_of_left * count_of_right;
                l++;
                r--; 
            }

        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a = pairSum(arr,n,4);
    cout<<a;
    return 0;
}