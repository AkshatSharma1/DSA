#include<iostream>
using namespace std;

class node
{
    public: 
        int data;
        node*next;

        //Constructor
        node(int d)
        {
            data=d;
            next=NULL;
        }
};

void insertAtTail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    //Traverse till end
    node*tail= head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next = new node(data);
    return;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head-> next;
    }
    cout<<endl;
}

//user input data
//M-1(if return type is node)
//make a new head pointer and add nodes and return it
node* take_input()
{
    int d;
    cin>>d;
    node*head=NULL;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
    }
    //if input from file, then use while(cin>>d)
    return head;
}


// void operator<<(ostream &os,node*head)
// {
//     print(head);

//     return ;
// }

//here return type is output stream
ostream& operator<<(ostream &os,node*head)
{
    print(head);

    return os;
}

istream& operator>>(istream &is, node*&head)//&head as we want to change content
{
    head=take_input();
    return is;
}



//Mid Point Of LL
node* midPoint(node*head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }

    node*slow=head;
    node*fast=head->next; //to remove problem in case of even length LL

    while(fast->next!=NULL and fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}



//Merge two sorted LL into one sorted LL
node* merge(node*a,node*b)
{
    //Base case
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }

    //new node pointer
    node*c=NULL;

    //Rec case
    if(a->data <= b->data)
    {
        c=a;
        c->next = merge(a->next,b);
    }
    else
    {
        c=b;
        c->next = merge(a,b->next);
    }
    return c;
}

node* mergeSort(node*head)
{
    //Base
    if(head==NULL or head->next==NULL)
    {
        return head;
    }

    //Rec case
    //Break in two from mid
    node*mid = midPoint(head);
    node*a=head;
    node*b=mid->next;

    mid->next=NULL;

    //Recursively sort
    a=mergeSort(a);
    b=mergeSort(b);

    //Store new
    node*c = merge(a,b);
    return c;
}

int main()
{
   
    node*head;
    cin>>head;
    
    cout<<"Original LL is:";
    cout<<head;

    node*newhead = mergeSort(head);
    cout<<newhead;

    return 0;
}