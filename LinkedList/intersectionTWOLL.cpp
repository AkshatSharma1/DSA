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

node* intersect(node*a,node*b)
{
    node*head=NULL;
    node*curr=NULL;

  
    while(a!=NULL and b!=NULL)
    {
        if((a->data)==(b->data))
        {
           if(head==NULL)
           {
               node* pushD = new node(a->data);
               head=pushD;
               curr=pushD;
           }
           else
           {
               node*pushD = new node(a->data);
               curr->next=pushD;
               curr=curr->next;
           }
            a=a->next;
            b=b->next;
        }

        else if((a->data)<(b->data))
        {
            a=a->next;
        }

        else
        {
            b=b->next;
        }
    }
    
    return head;
}

// node* recIntersection(node*a,node*b)
// {
//     if(a==NULL or b==NULL)
//     {
//         return NULL;
//     }

//     if((a->data)<(b->data))
//     {
//         return recIntersection(a->next,b);
//     }

//     if((a->data)>(b->data))
//     {
//         return recIntersection(a,b->next);
//     }

//     if((a->data)==(b->data))
//     {
//         node* pushD = new node(a->data);
//         pushD->next = recIntersection(a->next,b->next);
//         return pushD;
//     }
    
// }

int main()
{
    node*head1=NULL;
    node*head2=NULL;
    int n; cin>>n;
    int m; cin>>m;

    buildLL(head1,n);
    buildLL(head2,m);

    cout<<"Original Linked List is: "<<head1<<head2;

    node*head3 = recIntersection(head1,head2);

    cout<<"The modified linked list is: "<<head3;
    

    return 0;
}