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

node* insertAtHead(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    // if not NULL then
    node*n = new node(d);
    n->next=head;
    head=n;
}

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

int length(node*head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insertAtMiddle(node*&head, int d,int pos)
{
    //Traverse to position pos
    if(head==NULL || pos==0)
    {
        insertAtHead(head, d);
    }
    else if (pos>length(head))
    {
        insertAtTail(head, d);
    }
    else
    {
        //Take pos-1 jumps
        int jump=1;
        node*temp=head;
        while(jump<=pos-1)
        {
            temp=temp->next;
            jump++;
        }
        //New node
        node *n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }
}

void deleteAtHead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    //store next to second node to head
    node*temp=head->next;
    delete head;
    head=temp;
}

void deleteAtMiddle(node*&head,int pos)
{
    if(head==NULL || pos==0)
    {
        deleteAtHead(head);
    }
    //store next to previous node of node which is to be deleted to next of node to be deleted
    node*deleted;//node to be deleted
    node*temp=head;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    deleted=temp->next;
    temp->next=deleted->next;

    delete deleted;
}

void deleteAtEnd(node*&head)
{
    node*temp;
    temp=head;
    node*prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
        delete temp;
    }
    else
    {
        prev->next=NULL;
        delete temp;
    }
}

bool search(node*head,int key)// no &head as we only want to search through values
{
    //Traversing
    while(head->next!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
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

int main()
{
    node*head=NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtMiddle(head,5,3);
    insertAtMiddle(head,6,2);
    insertAtTail(head,10);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtMiddle(head,2);
    print(head);
    deleteAtEnd(head);
    print(head);
    if(search(head,0)==true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}