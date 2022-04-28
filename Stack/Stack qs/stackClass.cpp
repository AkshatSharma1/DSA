#include <climits>
class StackUsingArray
{
    int *data;     // pointer to array
    int nextIndex; // next index to insert in
    int capacity;  // shows total size of atck

public:
    // constructor
    // standard array
    //  StackUsingArray(int totalSize){
    //      data = new int(totalSize);
    //      nextIndex = 0; //initial
    //      capacity = totalSize;
    //  }

    // Dynamic array
    StackUsingArray()
    {
        data = new int(4);
        nextIndex = 0; // initial
        capacity = 4;
    }

    // return size(no. of elemenst currently in stack)
    int size()
    {
        return nextIndex;
    }

    // is empty
    bool isEmpty()
    {

        return nextIndex == 0;
    }

    // insert
    void push(int val)
    {

        if (nextIndex == capacity)
        {
            // double the capacity
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2

                // delete old
            delete[] data;
            data = newData;
        }
        data[nextIndex] = val;
        nextIndex++;
    }

    // pop
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top
    int top()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};