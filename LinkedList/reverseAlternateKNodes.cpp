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

node* kAltRev(node*head,int k)
{
    //Base case 
    if(head==NULL) return head;

    //Reversing the first K nodes 
    node*temp = head;
    node*headNext = NULL;
    node*prev = NULL;
    int count=0;

    while(temp!=NULL and count<k)
    {
        headNext = temp->next;
        temp->next = prev;
        prev = temp;
        temp=headNext;
        count++;
    }

    //change head to temp or headNext
    if(head!=NULL)
    {
        head->next = headNext;
    }

    //Traversing the alternate k nodes
    count=0;
    while(count<k-1 and headNext!=NULL)
    {
        headNext = headNext->next;
        count++;
    }

    //rec call on nodes after alternate ones
    if(headNext!=NULL)
    {
        //new head here is headNext
        headNext->next = kAltRev(headNext->next,k);
    }

    return prev;
}

int main()
{
    node*head1=NULL;
    
    int n,k; cin>>n>>k;

    buildLL(head1,n);

    cout<<"Original Linked List is: "<<head1;

    node* newLL = kAltRev(head1,k);

    cout<<"The reverse of Alternate K nodes of linked list is: "<<newLL;
    

    return 0;
}