#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;//size of grid array
        cin>>n;

        char** arr = new char*[n];
        for(int i=0;i<n;i++)//for each row make a row
        {
            arr[i] = new char[n];
        }

        //Take Input
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        cout<<endl;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

            // Transposed
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            arr[j][i] = arr[i][j];
            }
        }

        cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}