#include<bits/stdc++.h>
using namespace std;

void solve(int ones,int zeros,int n,string out)
{
    //Base case 
    if(n==0)
    {
        cout << out << endl;
        return;
    }

    //Get the "1" first
    string op1 = out;
    op1.push_back('1');
    solve(ones + 1, zeros, n - 1, op1);

    //Zeros choice
    if(ones>zeros)
    {
        string op2 = out;
        op2.push_back('0');
        solve(ones, zeros + 1, n - 1, op2);
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    cout << endl;
    solve(0, 0, n, "");

    return 0;
}