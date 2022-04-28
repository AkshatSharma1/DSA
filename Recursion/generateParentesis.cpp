#include<bits/stdc++.h>
using namespace std;

// void solve(int open, int close, string out, vector<string> &v);

// vector<string> getAns(int n)
// {
//     vector<string> v;
//     int open = n;
//     int close = n;

//     string out = "";

//     solve(open, close, out, v);

//     return v;
// }

// void solve(int open, int close, string out, vector<string> &v)
// {
//     //Base case
//     if(open == 0 && close == 0)
//     {
//         v.push_back(out);
//         return;
//     }

//     //Choices

//     //Open bracket choice
//     if(open!=0)
//     {
//         string op1 = out;
//         op1.push_back('(');

//         //Call for open-1
//         solve(open - 1, close, op1, v);
//     }

//     //Closing bracket choices
//     if(close>open)
//     {
//         string op2 = out;
//         op2.push_back(')');
//         solve(open, close - 1, op2, v);
//     }
// }

void solve(vector<string> &v, string str, int n, int m);

vector<string> getAns(int n) {
    vector<string> v;
    solve(v, "", n, 0);
    return v;  
}

void solve(vector<string> &v, string str, int n, int m){
    if(n==0 && m==0) {
        v.push_back(str);
        return;
    }
    if(m > 0)
    { 
        solve(v, str+")", n, m-1); 
    }

    if(n > 0)
    { 
        solve(v, str+"(", n-1, m+1); 
        
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> v;

    v = getAns(n);

    for(auto i: v)
    {
        cout << i << endl;
    }

    return 0;
}