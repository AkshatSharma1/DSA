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

// //Reversing A Linked List
// void reverse(node*&head)
// {
//     node*curr=head;
//     node*prev=NULL;
//     node*temp;

//     while(curr!=NULL)
//     {
//         temp = curr->next;//next node 
//         curr->next = prev;//point to prev node

//         prev = curr;
//         curr = temp;
//     }
//     head = prev;
// }

// node* recReverse(node*head)
// {
//     //Base Case
//     if(head->next==NULL or head==NULL)
//     {
//         return head;
//     }

//     //rec Case
//     node*smallHead = recReverse(head->next);
//     node*temp = smallHead;
//     while(temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
//     head->next=NULL;
//     temp->next=head;
//     return smallHead;
// }

// Mid Point Of LL
node* midPoint(node*head)
{
    if(head==NULL)
    {
        return head;
    }

    node*slow=head;
    // node*fast=head->next; // To get first middle in case of even linked_list
    node*fast=head; // to get 2nd middle and only middle in case of even and odd linkedlist respectively

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
    
}
int main()
{
    //here we are going to overload >> and << operator. We will simply do cout<<head and it will print the linked list.
    //similarly, to take input linkedlist using cin>>head, we overload it

    // node*head=take_input();
    // node*head2=take_input();
    node*head;

    cin>>head;

    //cout<<head; //for printing the linkedlist
    //cascading of operator,here, if we want to print two linkedlist, we use cout<<head<<head2.
    //But here cout<<head returned is void, then it becomes void<<head2(no meaning at all). So we need to change the return type, so new return type in ostream(i.e.,cout)
    cout<<"Original LL is:";
    cout<<head;

    node*mid = midPoint(head);
    cout<<"Mid is: "<<mid->data<<endl;


    return 0;
}