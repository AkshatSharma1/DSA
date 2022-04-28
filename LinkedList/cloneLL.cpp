//Pairwise swap
#include<bits/stdc++.h>
using namespace std;

class node
{
    public: 
        int data;
        node*next;
        node*random;

        //Constructor
        node(int d)
        {
            data=d;
            next=NULL;
            random=NULL;
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
        cout<<"Data = "<<head->data<<", Random = "<<head->random->data<<endl;
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

node* cloneList(node*head)
{
    node* curr = head;
    node*temp;

    //making a cloned LL inside the original LL
    while(curr)
    {
        temp=curr->next;
        curr->next = new node(curr->data);
        curr->next->next = temp;
        curr=temp;
    }

    curr=head;

    while(curr)
    {
        curr->next->random = curr->random?curr->random->next: curr->random;
        curr = curr-> next->next;
    }

    node*original = head;
    node*copy = head-> next;

    temp = copy;

    while(original and copy)
    {
        original->next = original->next->next;
        copy->next = copy->next?copy->next->next:copy->next;
        original = original-> next;
        copy= copy-> next;
    }
    return temp;
}


int main()
{
   
    node* start = new node(1);
    start->next = new node(2);
    start->next->next = new node(3);
    start->next->next->next = new node(4);
    start->next->next->next->next = new node(5);
  
    // 1's random points to 3
    start->random = start->next->next;
  
    // 2's random points to 1
    start->next->random = start;
  
    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;
  
    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;


    cout<<"Original LL is: \n";
    cout<<start<<endl;

    node*newLL = cloneList(start);
    cout<<"The Cloned List is: \n";
    cout<<newLL;
  
    
    return 0;
}