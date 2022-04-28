#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--) {

        int n,d;
        cin>>n>>d;

        int arr[n];
        memset(arr,0,sizeof arr);

        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        //sort the array acc to length
        sort(arr,arr+n);

        int i=0;
        int count=0;
        //now chk if the chopsticks can be paired,i.e, their length is nearby same,i.e, difference between them is equal to D
        while(i!=n) {

            if(abs(arr[i] - arr[i+1]) <= d)//max allowed diff of d
            {
                count++;//can be paired 
                //if paired then remove both arr[i] and arr[i+1] from the array(list)
                //thus
                i=i+2;
            }
            else
            {
                i=i+1;
            }

        }

    cout<<"Maximum usable pairs of chopsticks are: "<<count<<endl;
    }

    return 0;
}