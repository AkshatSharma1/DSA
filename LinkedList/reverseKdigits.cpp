//Reverse K digits at a time in  LL
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

void buildLL(node*&head,int n)
{
    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        insertAtTail(head,d);
    }
}

//Reverese k digits at a time
node* recReverse(node*head,int k)
{
    //Base case 
    if(head==NULL) return head;

    //rec case
    node*temp=head;
    node*next=NULL;
    node*prev=NULL;

    int count=0;

    while(temp!=NULL && count < k)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        count++;
    }

    if(next!=NULL)
    {
        head->next=recReverse(next,k);
    }
    return prev;

}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node*head = NULL;
    int n,k;
    cin>>n>>k;
    buildLL(head,n);
    //After we took the linked list input, reverse the linked list input
    head=recReverse(head,k);
    print(head);

    return 0;
}