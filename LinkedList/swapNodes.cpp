//Remove duplicates from a sorted linked list
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

void swap(node*&a,node*&b)
{
    node*temp=a;
    a=b;
    b=temp;
}

void swapNode(node**head, int x,int y)
{
    if(x==y)
    {
        return;
    }

    node**a =NULL;node** b=NULL;
    while(*head!=NULL)
    {
        if(((*head)->data)==x)
        {
            a=head;
        }
        else if (((*head)->data)==y)
        {
            b=head;            
        }
        head=&((*head)->next);
    }

    if(a&&b)
    {
        swap(*a,*b);
        swap((*a)->next,(*b)->next);
    }
}


// void swapNode(node*head, int x,int y)
// {
//     if(x==y)
//     {
//         return;
//     }

//     //search for x
//     node* prevX=NULL;
//     node* currX=head;

//     while(currX && currX->data!=x)
//     {
//         prevX = currX;
//         currX = currX-> next;
//     }

//     //search for y
//     node* prevY=NULL;
//     node* currY=head;

//     while(currY && currY->data!=y)
//     {
//         prevY = currY;
//         currY = currY-> next;
//     }

//     if(currX==NULL && currY==NULL)
//     {
//         return;
//     }

//     //If X is not head then
//     if(prevX!=NULL)
//     {
//         prevX->next=currY;
//     }
//     else
//     {
//         head=currY;
//     }

//     if(prevY!=NULL)
//     {
//         prevY->next=currX;
//     }
//     else
//     {
//         head = currX;
//     }

//     node*temp=currY->next;
//     currY->next=currX->next;
//     currX->next=temp;
// }

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
 
    int n;
    cin>>n;

    buildLL(head,n);
    int x,y;
    cin>>x>>y;
  

    cout<<"Original LL is:";
    cout<<head;

    swapNode(&head,x,y);
    cout<<head;

  
    
    return 0;
}