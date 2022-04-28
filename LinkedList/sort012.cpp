//Rotate list counter clockwise
//MOve Last element to front
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*next;

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
    cout<<"NULL";
    cout<<endl;
}

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

//Operator overloading
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

void buildLL(node*&head,int n)
{
    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        insertAtTail(head,d);
    }
}

node* sortLL(node*&head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    node*curr=head;
    node*temp=head;
    while(temp)
    {
        if(temp->data==0) zeroCount++;
        else if(temp->data==1) oneCount++;
        else if (temp->data==2) twoCount++;

        temp=temp->next;
    }


    for(int i=0;i<zeroCount;i++)
    {
        curr->data=0;
        curr=curr-> next;
    }

      for(int i=0;i<oneCount;i++)
    {
        curr->data=1;
        curr=curr-> next;
    }

      for(int i=0;i<twoCount;i++)
    {
        curr->data=2;
        curr=curr-> next;
    }

    return head;
}

int main()
{
    node*head1=NULL;
    
    int n; cin>>n;
    buildLL(head1,n);

    cout<<"Original Linked List is: "<<head1;
    cout<<endl;

    node* newLL = sortLL(head1);
    cout<<newLL;

    return 0;
}