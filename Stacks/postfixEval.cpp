#include<iostream>
#include <stack>
#include<math.h>

using namespace std;

int postfixEval(string s)
{
    stack<int> stk;
    for(int i=0;i<=s.length()-1;i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            stk.push(s[i]-'0');
        }
        else 
        {
            int op2 = stk.top(); stk.pop();
            int op1 = stk.top(); stk.pop();
            

            switch(s[i])
            {
                case '+': stk.push(op1 + op2); 
                break;

                case '-': stk.push(op1 - op2);
                break;

                case '*': stk.push(op1 * op2);
                break;

                case '/': stk.push(op1 / op2);
                break;

                case '^': stk.push(pow(op1,op2));
                break;
            }
        }

    }
    
        return stk.top();
}

int main() {

    cout<<postfixEval("46+2/5*7+");
    return 0;
}