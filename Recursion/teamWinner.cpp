#include<bits/stdc++.h>
using namespace std;

void newResult(string str,int countA,int countB) {
    int cA = countA;
    int cB = countB;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] =='a')
        {
            cA++;
        }
        if(str[i]=='b')
        {
            cB++;
        }
        if((cA-cB)==2)
        {
            cout << "Team A Wins";
            break;
        }
        if((cB-cA)==2)
        {
            cout<<"Team B Wins";
            break;
        }
    }
}

void timeout(int n,string s)
{
    int countA=0, countB=0;
    for (int i = 0;i<s.length();i++)
    {
        if(s[i]=='a')
        {
            countA++;
        }
        if(s[i]=='b')
        {
            countB++;
        }
        
        if(countA==n-1 and countB==n-1)
        {
            newResult(s.substr(i+1,s.length()),countA,countB);
            break;
        }
        if(countA==n)
        {
            cout << "Team A Wins";
            break;
        }

        if(countB==n)
        {
            cout << "Team B Wins";
            break;
        }
    }

}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    timeout(n, s);

    return 0;
}