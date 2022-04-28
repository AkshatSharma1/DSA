#include<bits/stdc++.h>
using namespace std;

void printSpelling(string *str, int n)
{
    //Base case:
    if(n==0)
        return;
    
    //Recursive call on each %modulo value print
    printSpelling(str, n / 10);
    cout << str[n % 10] << " ";
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    //string array
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "\n";
    cout << "Integer to string representation is as :"
         << "\n";

    printSpelling(str, n);

    return 0;
}