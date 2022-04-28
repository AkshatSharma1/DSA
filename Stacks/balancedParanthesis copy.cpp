#include<iostream>
#include<stack>
using namespace std;

bool isTrue(char *s)
{
    stack<char> stk;

    for (int i = 0; s[i] != '0'; i++)
    {
        char ch =s[i];
        if(char(ch) == '(')
        {
            stk.push(ch);
        }
        else if(char(ch) == ')')
        {
            if(!stk.empty() and stk.top()!='(')
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();

}

int main()
{
    char ch[100] = "(a+(b+c) + (d+e )";
    if(isTrue(ch))
    {
        cout<<"Valid"<<endl;
    } 
    else
    {
        cout<<"Not Valid";
    }

    return 0;
}