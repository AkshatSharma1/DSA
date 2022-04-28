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


node* addTwoLL(node*head1,node*head2)
{
    //resulting LL
    node*res = new node(-1);
    node*curr = res;//to loop over the result LL 

    int carry = 0;
    
    while(head1!=NULL or head2!=NULL)
    {
        int no1 = head1?head1->data:0;
        int no2 = head2?head2->data:0;

        int sum = no1 + no2 + carry;

        carry = sum/10;

        curr->next = new node(sum%10);//digit = sum%10;
        curr=curr->next;

        if(head1)
            head1=head1->next;
        if(head2)
            head2=head2->next;
    }
            //Now if carry remaining is >0
        if(carry>0)
        {
            curr->next = new node(9);

        }

        return res->next;
}

int main()
{
    node*head1=NULL;
    node*head2=NULL;
    
    int k; cin>>k;
    int j; cin>>j;
    

    buildLL(head1,k);
    buildLL(head2,j);

    cout<<"Original Linked List is: "<<head1<<head2;
    cout<<endl;

    node*newLL = addTwoLL(head1,head2);
    cout<<"The result LL is: "<<newLL<<endl;

    return 0;
}