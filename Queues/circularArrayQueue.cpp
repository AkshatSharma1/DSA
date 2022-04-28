#include<iostream>
using namespace std;

template<typename T>
class QueueUsingArray
{
    //data array
    T* data;
    int front;
    int rear;
    int size;
    int capacity;

    public:
        //constructor
        QueueUsingArray(int s)
        {
            data = new T[s];
            front = -1;
            rear = 0;
            size = 0;
            capacity = s;
        }

        int getSize() 
        { 
            return size;
        }

        bool isEmpty() 
        {
            return size == 0;
        }

        void enqueueSDynamic(T element)
        {
            //Check queue size
            if(size == capacity)
            {
                cout<<"Queue is full"<<endl;
                return;
            }

            data[rear] = element;
            rear = (rear + 1) % capacity;

            if(front == -1)
            {
                front++;
            }

            //whenever new elements is pushed increse size
            size++;
        }

        //Dynamic array case,i.e, no size overflow issue
        void enqueueDynamic(T element)
        {
            //Check queue size
            if(size == capacity)
            {
                // cout<<"Queue is full"<<endl;
                T* newData = new T[2*capacity];
                //copying data from old to new 
                int j=0;
                for(int i = front ;i <capacity;i++)
                {
                    newData[j++] = data[i];
                }

                for(int i=0;i<front ;i++)
                {
                    newData[j++] = data[i];
                }

                delete[] data;
                data = newData;
                //reset f and r
                front = 0;
                rear = capacity;
                capacity *= 2;

                // return;
            }

            data[rear] = element;
            rear = (rear + 1) % capacity;

            if(front == -1)
            {
                front++;
            }

            //whenever new elements is pushed increse size
            size++;
        }

        T peek()
        {
            if(front == -1 || isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }

            return data[front];
        }

        //Popping and returning data
        T dequeue()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }

            T ans = data[front];
            front = (front + 1) % capacity;
            size--;

            //reset the f and r when queue is empty
            if(size == 0)
            {
                front = -1;
                rear = 0;
            }

            return ans;
        }
};

int main()
{
    QueueUsingArray<int> q(5);

    q.enqueueDynamic(10);
    q.enqueueDynamic(20);
    q.enqueueDynamic(30);
    q.enqueueDynamic(40);
    q.enqueueDynamic(50);
    q.enqueueDynamic(60);

    cout<<q.peek()<<endl;
    
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    

    return 0;
}