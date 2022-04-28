// Remove duplicate in unsorted linked list
//Firstly make unsorted list to sorted list

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


void buildLL(node*&head,int n)
{
    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        insertAtTail(head,d);
    }
}

void insertSorted(node*&head, node*new_node)
{
    node* temp;
    /* Special case for the head end */
    if (head== NULL || (head)->data >= new_node->data)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        temp = head;
        while (temp->next!=NULL &&
               temp->next->data < new_node->data)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}


void insertionSort(node*head)
{
    node* sorted = NULL;
    node*curr=head;

    while(curr!=NULL)
    {
        node*next = curr->next;

        insertSorted(sorted,curr);

        curr=next;
    }
    head=sorted;
}

void removeDuplicate(node*head)
{
    if(head==NULL)
    {
        return;
    }
    
    node*curr=head;
    node* currNext;
    while(curr->next!=NULL)
    {
        
        if((curr->data)==(curr->next->data))
        {
            currNext = curr->next->next;
            delete curr->next;
            curr->next = currNext; 

        }
        else
        {
            curr=curr->next;
        }
    }

}


int main()
{
   
    node*head=NULL;
 
    int n;
    cin>>n;

    buildLL(head,n);
  

    cout<<"Original LL is:";
    cout<<head;

    insertionSort(head);
    cout<<"Sorted LL is:";
    cout<<head;

    removeDuplicate(head);
    cout<<head;

  
    
    return 0;
}