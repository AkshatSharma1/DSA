#include<bits/stdc++.h>
using namespace std;

void solve(string in,string out)
{
    //Base case 
    if(in.length()==0)
    {
        cout << out << endl;
        return;
    }

    //Rec callback
    //Two choices: a) Either to include lower case
    //             b) Either to include upper case

    //Lowe case
    solve(in.substr(1), out + in[0]);

    //Upper case
    solve(in.substr(1), out + string(1, toupper(in[0])));
}


int main()
{
    string inp;
    cin >> inp;

    string out;

    cout << "\n";
    solve(inp, out);

    return 0;
}