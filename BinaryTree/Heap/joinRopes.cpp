#include<iostream>
#include<queue>
using namespace std;

int joinRopes(int ropes[],int n)
{
    //automatically create a min heap by using vaname(arr,arr+n)
    priority_queue<int,vector<int>,greater<int> > pq(ropes,ropes+n);

    int cost = 0;

    while(pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int newRope = A+B;
        cost+=newRope;
        pq.push(newRope);
    }
    return cost;
}
int main()
{
    int ropes[]={4,3,2,6};
    int n = sizeof(ropes)/sizeof(ropes[0]);

    cout<<"MIn Cost to join ropes is: "<<joinRopes(ropes,n);
    
    return 0;
}