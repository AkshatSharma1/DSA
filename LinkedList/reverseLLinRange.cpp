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

node* revSublist(node*&head,int m,int n)
{
    node*prev = NULL;
    node*curr = head;

    for(int i=1;curr!=NULL and i<m ;i++)
    {
        prev = curr;
        curr = curr->next;
    }

    //Store the start(head) of sublist 
    node* subHead = curr;
    node* subEnd = NULL;

    //reversing code
    for(int i=1;curr!=NULL and i<=n-m+1; i++)
    {
        node*currNext = curr->next;
        curr->next = subEnd;
        subEnd = curr;
        curr = currNext;
    }

    subHead->next = curr;
    
    if (prev != NULL) {
        prev->next = subEnd;
    }
    else {
        
        head = subEnd;
    }
}



int main()
{
    node*head1=NULL;
    
    int k; cin>>k;
    int m,n; cin>>m>>n;

    buildLL(head1,k);

    cout<<"Original Linked List is: "<<head1;
    cout<<endl;

    node* revList = revSublist(head1,m,n);
    cout<<"Reversed List is: "<<revList;
    

    return 0;
}