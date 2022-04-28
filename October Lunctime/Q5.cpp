#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {

        int n, v;
        cin >> n >> v;

        int mini = 0;
        int maxi = 0;

        maxi = n * (n - 1) / 2;

        if(v==1) {
            mini = maxi;
            cout<<maxi<<" "<<mini<<endl;
        }
        else
        {
            if(v>=n-1)
            {
                mini = n - 1;
            }
            else
            {
                mini = (v * 1) + ((n - v) * (n - v + 1))/2 - 1;
            }
            cout<<maxi<<" "<<mini<<endl;
        }
        
    }
    return 0;
}