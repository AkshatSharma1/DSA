#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int x,k;
        cin>>x>>k;
        
        int y = x*k;
        
        int mini = x * 2;
        int maxi = y*(y-1);
    
        cout<<mini<<" "<<maxi;
        cout<<endl;
    }
    return 0;
}