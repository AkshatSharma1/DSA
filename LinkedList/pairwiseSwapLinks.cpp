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

node* pairwiseSWap(node*head)
{
    node* prev = head;
    node*curr = head->next;

    head = curr;

    while(true)
    {
        node*currNext = curr->next;
        curr->next = prev;
        
        if(currNext==NULL or currNext->next==NULL)
        {
            prev->next = currNext;
            break;
        }

        prev->next = currNext->next;
        prev = currNext;
        curr = prev->next;

    }
    return head;
}

node* recPairwiseSWap(node*head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }

    node* toBeRecursiveCalled = head->next->next;

    node*newHead = head-> next;

    head->next->next = head;

    //rec calling
    head->next = recPairwiseSWap(toBeRecursiveCalled);

    return newHead;
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
    int m; cin>>m;

    buildLL(head,n);
    buildLL(head1,m);

    cout<<"Original LL is:";
    cout<<head<<head1<<endl;

    node*newLL = pairwiseSWap(head);
    cout<<newLL<<endl;

    node*newLL1 = recPairwiseSWap(head1);
    cout<<newLL1<<endl;
  
    
    return 0;
}