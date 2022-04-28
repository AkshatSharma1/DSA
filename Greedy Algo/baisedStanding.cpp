#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
    int arr[100000] = {0};//initialise with 0 frequency for counting
    int t,n;
    cin>>t;

    while(t--) {

        //reset freq array to 0 for each test case using memset
        memset(arr,0,sizeof arr);
        string name;
        int n,rank;
        cin>>n;//no.of teams

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>name>>rank;
            arr[rank]++; //if rank already then incremented by +1 else added
        }

        //Greedy Approaching
        int actualRank = 1;//starting from 1
        for(int i=1;i<=n;i++)
        {
                while(arr[i])
                {
                    sum+=abs(actualRank - i);
                    arr[i]--;
                    actualRank++;
                }
        }
        cout<<sum<<endl;
        
    }
    return 0;
}