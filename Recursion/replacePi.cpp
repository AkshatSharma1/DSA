#include<bits/stdc++.h>
using namespace std;

void replacePi(string str)
{
    //Base case
    if(str.length()==0 or str.length()==1)
        return;
    
    //Rec case

    //If p and i present consecutive at start
    if(str[0]=='p' or str[0]=='i')
    {
        cout << "3.14";
        replacePi(str.substr(2));
    }
    else
    {
        cout << str[0];
        replacePi(str.substr(1));
    }
}

int main()
{
    string s = "xpighpimpipipighpiddpidpidpidpi";
    replacePi(s);
    return 0;
}
