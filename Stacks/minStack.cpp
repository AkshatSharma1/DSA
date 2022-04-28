// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Extra space method
class Stack
{
    stack<int> s1;
    stack<int> hs;

    public:

        void push(int x) 
        {
            s1.push(x);
            if(hs.empty() || hs.top()>=x)
            {
                hs.push(x);
                return;
            }
            
        }

        void pop() 
        {
            if(s1.top()==hs.top())
            {
                hs.pop();
            }
            s1.pop();

        }

        int top()
        {
            return s1.top();
        }

        int getMin()
        {
            if(hs.empty())
            {
                return -1;
            }
            return hs.top();
        }
};

//constant space method
class MyStack
{
    stack<int> s1;
    int min = INT_MAX;

public:
    void push(int x)
    {
        if(s1.empty())
        {
            s1.push(x);
            min = x;
        }

        else
        {
            if(x>min)
            {
                s1.push(x);
            }
            else if (x<min)
            {
                s1.push(2*x - min);
                min = x;
            }
        }
    }

    void pop()
    {
        if(s1.empty())
        {
            return ;
        }
        else
        {
            if(s1.top()>min)
            {
                s1.pop();
            }
            else if(s1.top()<min)
            {
                min = 2*min - s1.top();
                s1.pop();
            }
        }
    }

    int top()
    {
        if(s1.empty()) return -1;

        else
        {
            if(s1.top()>min)
            {
                return s1.top();
            }
            else if(s1.top()<min)
            {
                return min;
            }
        }
    }

    int getMin()
    {
            if(s1.empty())
            {
                return -1;
            }
            return min;
    }
};

int main()
{
    MyStack s;
 
    s.push(6);
    cout << s.getMin() << endl;    // prints 6
 
    s.push(7);
    cout << s.getMin() << endl;    // prints 6
 
    s.push(8);
    cout << s.getMin() << endl;    // prints 6
 
    s.push(5);
    cout << s.getMin() << endl;    // prints 5
 
    s.push(3);
    cout << s.getMin() << endl;    // prints 3
 
    s.pop();
    cout << s.getMin() << endl;    // prints 5
 
    s.push(10);
    cout << s.getMin() << endl;    // prints 5
 
    s.pop();
    cout << s.getMin() << endl;    // prints 5
 
    s.pop();
    cout << s.getMin() << endl;    // prints 6
 
    return 0;
 
}