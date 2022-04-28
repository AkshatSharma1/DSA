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

void deleteAltNodes(node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }

    node*curr=head;
    node*temp=head->next;//to be deleted

    while(curr!=NULL && temp!=NULL)
    {
        curr->next = curr->next->next;// or temp->next
        free(temp);
        curr=curr-> next;

        if(curr!=NULL)
        {
            temp=curr-> next;
        }
    }
}

int main()
{
    node*head1=NULL;
    
    int n; cin>>n;

    buildLL(head1,n);

    cout<<"Original Linked List is: "<<head1;

    deleteAltNodes(head1);

    cout<<"The linked list after deleting alternate nodes is: "<<head1;
    

    return 0;
}