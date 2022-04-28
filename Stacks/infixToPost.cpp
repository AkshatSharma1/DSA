#include<iostream>
#include <stack>
#include<math.h>

using namespace std;

int precision(char c)
{
    if(c =='^')
    {
        return 3;
    }
    else if(c=='*' or c=='/')
    {
        return 2;
    }
    else if(c=='+' or c=='-')
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}

string infixToPost(string s)
{
    stack<char> stk;
    string result;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))
        {
            result+=s[i];
        }
        else if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!stk.empty() and stk.top()!='(')
            {
                result+=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else 
        {
            while(!stk.empty() and precision(stk.top())>precision(s[i]))
            {
                result+=stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    //if string parsed and some elements left in stacks
    while(!stk.empty())
    {
        result+=stk.top();
        stk.pop();
    }

    return result;
}

int main()
{
    cout<<infixToPost("(a-b)/c*(a/k-l)");
    return 0;
}
