#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;

        if(x>=1 and x<100)
        {
            cout << "Easy" << endl;
        }

        else if(x>=100 and x<200)
        {
            cout << "Medium" << endl;
        }

        else if(x>=200 and x<300)
        {
            cout << "Hard" << endl;
        }
    }
    return 0;
}