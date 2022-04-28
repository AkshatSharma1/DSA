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

int count(node* head)
{
int ans = 0;

    while(head)
    {
        ans++;
        head = head->next;
    }
    
    return ans;
}

void intersect(node*&head1,node*&head2,int pos)
{
    pos--;
    node*temp1=head1;
    while(pos--)
    {
        temp1=temp1->next;
    }

    node*temp2=head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }

    temp2->next=temp1;
}

int intersection(node*head1,node*head2)
{
    int l1=count(head1);
    int l2=count(head2);
    int d=0;
    node*ptr1=head1;
    node*ptr2=head2;

    if(l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d--)
    {
        ptr1=ptr1->next;
        if(ptr1->next==NULL)
        {
            return -1;
        }
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

int main()
{
    node*head1=NULL;
    node*head2=NULL;
    int n; cin>>n;
    int m; cin>>m;

    buildLL(head1,n);
    buildLL(head2,m);

    cout<<"Original Linked List is: "<<head1<<head2;

    intersect(head1,head2,3);
    cout<<"After Intersection: "<<head1<<head2;

    int point = intersection(head1,head2);

    cout<<"The intersection point of linked list is: "<<point;
    

    return 0;
}