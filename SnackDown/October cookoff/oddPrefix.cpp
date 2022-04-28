#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if(n==1) {
            cout << "1" << endl;
        }

        else if(n==2 or n==3) {
            cout << "3" << endl;
        }

        else 
        {
            int m = 3 + n * (n - 3);
            cout << m << endl;
        }
        
    }
    return 0;
}