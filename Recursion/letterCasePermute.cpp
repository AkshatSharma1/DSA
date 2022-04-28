#include<bits/stdc++.h>
using namespace std;

void solve(string in, string out, vector<string> &v);

vector<string> getAns(string s)
{
    string in = s;
    string out = "";

    vector<string> v;
    solve(in, out, v);

    return v;
}

void solve(string in,string out,vector<string> &v)
{
    //base case 
    if(in.length()==0)
    {
        v.push_back(out);
        return;
    }

    //Rec callback

    //Check if current input is digit or character
    if(isalpha(in[0]))
    {
        //Two choices
        //a) if in[0] -> lowercase then convert to upper case and add
        //b) if in[1] -> lowercase then add

        string op1 = out;
        string op2 = out;
        op1.push_back(tolower(in[0]));
        op2.push_back(toupper(in[0]));

        solve(in.substr(1), op1,v);
        solve(in.substr(1), op2,v);

        // //Lowecase
        // solve(in.substr(1), string(1,tolower(in[0])), v);

        // //Uppercase
        // //string(1,value) -> to convert char to string
        // solve(in.substr(1), string(1, toupper(in[0])), v);
    }

    else
    {
        string op1 = out;
        op1.push_back(in[0]);
        solve(in.substr(1), op1, v);
        // solve(in.substr(1), string(1,in[0]), v);
    }
}

int main()
{
    string input = "a1B2";
    

    vector<string> res = getAns(input);
    cout << endl;

    for(auto i: res)
    {
        cout<<i<<endl;
    }

    return 0;
}