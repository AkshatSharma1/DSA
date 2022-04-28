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


void rotate(node*&head,int k)
{
    node*prev = NULL;
    node*curr = head;
    for(int i=0;i<k;i++)
    {
        prev = curr;
        curr=curr-> next;
    }
    prev->next = NULL;

    node*temp=curr;
    int count=0;
    while(temp->next!=NULL)
    {
        temp=temp-> next;
        count++;
    }
    temp->next=head;
    head=curr;
}

int main()
{
    node*head1=NULL;
    
    int n; cin>>n;
    int k; cin>>k;

    buildLL(head1,n);

    cout<<"Original Linked List is: "<<head1;
    cout<<endl;

    rotate(head1,k);
    cout<<head1;

    return 0;
}