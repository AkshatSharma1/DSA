#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        char a;
        int flag = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> a;
            s.push_back(a);
        }

        for(int i = 0; i < n-1; i++)
        {
            if(s[i]=='L' and s[i+1]=='L')
            {
                flag = 1;
            }
            else if(s[i]=='R' and s[i+1]=='R')
            {
                flag = 1;
            }
        }

        if(flag==1)
        {
            cout << "YES"<<endl;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }
    return 0;
}