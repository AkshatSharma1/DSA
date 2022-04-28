#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int> &stk,int n,int curr) {
    
    //Base case
    if(stk.empty() or curr==n)
    {
        return;
    }

    int x = stk.top();
    stk.pop();

    deleteMid(stk,n,curr+1);

    if(curr!=n/2)
    {
        stk.push(x);
    }
}

void print(stack<int> &stk)
{
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    // stk.push(8);

    int n = stk.size();

    // print(stk);

    deleteMid(stk,n,0);

    print(stk);

    return 0;
}