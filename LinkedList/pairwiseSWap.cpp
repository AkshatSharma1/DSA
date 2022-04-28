//Pairwise swap
#include<bits/stdc++.h>
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


void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head-> next;
    }
    cout<<endl;
}

//user input data
//M-1(if return type is node)
//make a new head pointer and add nodes and return it
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

//M-2(if return type void and head is passed as reference and nodes added to the head)
void take_input_2(node*&head, int data)
{
    node*temp=new node(data);
    temp->data=data;
    temp->next=head;
    head=temp;
}

// void operator<<(ostream &os,node*head)
// {
//     print(head);

//     return ;
// }

//here return type is output stream
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

void pairwiseSWap(node*head)
{
    node*temp=head;
    while(temp!=NULL and temp->next!=NULL)//first and second node should be present
    {
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
}

void recPairwiseSWap(node*head)
{
    if(head!=NULL and head->next!=NULL)
    {
        swap(head->data,head->next->data);
        recPairwiseSWap(head->next->next);
    }
}

void buildLL(node*&head,int n)
{
    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        insertAtTail(head,d);
    }
}



int main()
{
   
    node*head=NULL;
    node*head1=NULL;
 
    int n;
    cin>>n;
    int m;
    cin>>m;

    buildLL(head,n);
    buildLL(head1,m);
  

    cout<<"Original LL is:";
    cout<<head<<head1<<endl;

    pairwiseSWap(head);
    cout<<head<<endl;

    recPairwiseSWap(head1);
    cout<<head1;
  
    
    return 0;
}