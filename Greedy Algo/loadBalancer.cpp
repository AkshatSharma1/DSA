//Make each processor(block of array) have equal task(equal height)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int arr[10000];
    while(t--)
    {
        int max_load = 0;
        int load = 0;//sum of array

        int n;//processors
        cin>>n;

        if(n==-1)
        {
            break;
        }

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            load += arr[i];
        }

        //Now if sum/n gives floating value i.e. remainder!=0 then return -1
        if(load%n != 0)
        {
            cout<<"-1"<<endl;
            continue;
        }

        //find the load on each processor needed
        load = load/n;
        int diff = 0;

        //greedy process
        for(int i=0; i<n; i++)
        {
            //find out difference between current load and load needed in a running way
            diff+=(arr[i] - load);
            int ans = max(diff,-diff);//absolute value

            max_load = max(max_load,ans);
        }
        cout<<max_load<<endl;

        return 0;

    }
}

/*---
    Input:  1(test cases)
            4(processors)
            0 6 10 0(load values)

    Output: 4(min 4 rounds needed for making [4,4,4,4])