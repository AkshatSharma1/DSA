#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> leftHeap; //Max heap 
    priority_queue<int,vector<int>,greater<int>> rightHeap; //min heap

    //input elements
    int d; cin>>d;
    //first element is pushed to left heap
    leftHeap.push(d);

    float med = d; //initially when first element is pushed
    cout<<"Median is: "<<med<<endl;

    cin>>d;// 2nd element onwards

    //input all elements
    while(d!=-1)
    {
        //logic
        if(leftHeap.size() > rightHeap.size()) //max > min
        {
            if(d<med)//if data is less than the current Median
            {
                rightHeap.push(leftHeap.top());//pop top from left and push to right heap
                leftHeap.pop();
                leftHeap.push(d);
            }

            else
            {
                rightHeap.push(d);
            }

            med = (leftHeap.top() + rightHeap.top())/2.0;
        }

        else if (leftHeap.size() == rightHeap.size())
        {
            if(d<med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else
            {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }

        else //when right > left
        {
            if(d>med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }

            med = (rightHeap.top() + leftHeap.top())/2.0;
        }

        cout<<"Median is: "<<med<<endl;
        cin>>d;//take elements
    }

return 0;
}