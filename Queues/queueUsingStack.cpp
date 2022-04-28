#include<bits/stdc++.h>
using namespace std;

//Using 2 stacks
// class Queue{
//     stack<int> s1;
//     stack<int> s2;

//     public:
//         void push(int x)
//         {
//             s1.push(x);
//         }

//         int pop(){
//             if(s1.empty() & s2.empty())
//             {
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             if(s2.empty()){
//                 while(!s1.empty())
//                 {
//                     s2.push(s1.top());
//                     s1.pop();
//                 }
//             }

//             int poppedValue = s2.top();
//             s2.pop();

//             return poppedValue;
//         }

//         bool empty(){
//             if(s1.empty() and s2.empty()){
//                 return true;
//             }
//             return false;
//         }
// };

//using 1 stack only and function call stack
class Queue{
    stack<int> s1;

    public:
        void push(int x)
        {
            s1.push(x);
        }

        int pop(){
            if(s1.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            //recursively pop elements from the stack
            int x = s1.top();
            s1.pop();

            if(s1.empty()) //if only 1 element was there and now empty
            {
                return x;
            }

            //if not, then recursive pop elements

            int ele = pop();//rec call
            s1.push(x);

            return ele;

        }

        bool empty(){
            if(s1.empty()){
                return true;
            }
            return false;
        }

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    q.push(8);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;



    return 0;
}