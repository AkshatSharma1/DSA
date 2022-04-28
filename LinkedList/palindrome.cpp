//Q15. Palindrome
//GFG LL
//Q.12 Write a function that counts the number of times a given int occurs in a Linked List
//Given a singly linked list and a key, count number of occurrences of given key in linked list. For example, if given linked list is 1->2->1->2->1->3->1 and given key is 1, then output should be 4.

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


node* recReverse(node*head)
{

    node*prev=NULL;
    node*next=NULL;

    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev = head;
        head=next;
    }
    return prev;
}

bool isPalindrome(node*head)
{
    if(head==NULL or head->next==NULL)
    {
        return true;
    }

    node*dummy = head;
    node*slow=head;
    node*fast=head->next; // To get first middle in case of even linked_list
    // node*fast=head; // to get 2nd middle and only middle in case of even and odd linkedlist respectively

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    //reverse the right half of the linked list
    slow->next = recReverse(slow->next);

    //slow to the reversed first node of right half
    slow = slow->next;

    //Check palindrome
    while (slow!=NULL)
    {
        if(dummy->data!=slow->data)
        {
            return false;
        }
        dummy = dummy->next;
        slow = slow->next;
        
    }
return true;

}


int main()
{
   
    node*head=NULL;
 
    int n;
    cin>>n;

    buildLL(head,n);
  

    cout<<"Original LL is:";
    cout<<head;

    if(isPalindrome(head))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
  
    
    return 0;
}