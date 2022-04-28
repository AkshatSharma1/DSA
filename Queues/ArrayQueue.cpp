#include<iostream>
#define n 20
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;

    public:

        Queue()
        {
            arr = new int[n];
            front = -1;
            rear = -1;
        }

        //Member functions
        void push(int x)
        {
            if(rear == n-1)
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }

            rear++; 
            arr[rear] = x;

            if(front == -1)
            {
                front++;
            }
        }

        bool empty()
        {
            if(front == -1 || front>rear)
            {
                return true;
            } 
            return false;
        }

        void pop()
        {
            if(empty())
            {
                cout<<"No elements in the Queue"<<endl;
                return;
            }

            front++;
        }

        int peek()
        {
            if(empty())
            {
                cout<<"No elements in the Queue"<<endl;
                return -1;
            }
            return arr[front];
        }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    return 0;
}
