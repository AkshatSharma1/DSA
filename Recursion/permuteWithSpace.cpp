#include<bits/stdc++.h>
using namespace std;

void solve(string inp,string out)
{
    //Base case
    if(inp.length() == 0)
    {
        cout << out << endl;
        return;
    }

    //Rec call
    //two choices are: either to include character withspace or not
    solve(inp.substr(1), out + " " + inp[0]);
    //Do not include space
    solve(inp.substr(1), out + inp[0]);
}

int main()
{
    string in;
    cin >> in;

    string out;

    //GET THE 0TH INDEX IN OUTPUT
    out = out + in[0];
    cout << endl;
    solve(in.substr(1), out);

    return 0;
}