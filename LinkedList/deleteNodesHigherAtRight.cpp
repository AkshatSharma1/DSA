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

void reverse(node*&head)
{
    node*curr=head;
    node*prev=NULL;
    node*temp;

    while(curr!=NULL)
    {
        temp = curr->next;//next node 
        curr->next = prev;//point to prev node

        prev = curr;
        curr = temp;
    }
    head = prev;
}

void deleteNodes(node*&head)
{
    reverse(head);
    node*curr=head;
    node*maxNode=head;
    node*temp;

    while(curr!=NULL and curr->next!=NULL)
    {
        if(curr->next->data < maxNode->data)
        {
            temp = curr->next;
            curr->next = temp->next;free(temp);
        }

        else
        {
            curr=curr->next;
            maxNode=curr;
        }
    }

    reverse(head);
}



int main()
{
    node*head1=NULL;
    
    int k; cin>>k;
    

    buildLL(head1,k);

    cout<<"Original Linked List is: "<<head1;
    cout<<endl;

    deleteNodes(head1);
    cout<<head1;

    return 0;
}