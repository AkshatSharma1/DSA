//Rotate list counter clockwise
//MOve Last element to front
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*next;
        node*bottom;

        node(int d)
        {
            data=d;
            next=NULL;
            bottom=NULL;
        }
};

// void insertAtTail(node*&head,int data)
// {
//     if(head==NULL)
//     {
//         head=new node(data);
//         return;
//     }
//     //Traverse till end
//     node*tail= head;
//     while(tail->next!=NULL)
//     {
//         tail=tail->next;
//     }
//     tail->next = new node(data);
//     return;
// }

void push (node* &head, int new_data)
{
    /* allocate node */
    node* new_node = new node(new_data);
    new_node->next = NULL;
  

  
    /* link the old list off the new node */
    new_node->bottom = head;
  
    /* move the head to point to the new node */
    head    = new_node;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head-> bottom;
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
        push(head,d);
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
        push(head,d);
    }
}

node*merge(node*a,node*b)
{
    node*temp=new node(0);
    node*res = temp;

    while(a && b)
    {
        if(a->data<b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if(a!=NULL)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }
    res->next = NULL;

    return res->bottom;
}

node*flatten(node*root)
{
    if(root == NULL or root->next == NULL)
    {
        return root;
    }

    //rec call
    root->next = flatten(root->next);

    //merge
    root = merge(root,root->next);

    return root;
}

int main()
{
    node*root=NULL;
    
    // int n; cin>>n;

    // buildLL(head1,n);

    push( root, 30 );
    push( root, 8 );
    push( root, 7 );
    push( root, 5 );
  
    push( ( root->next ), 20 );
    push( ( root->next ), 10 );
  
    push( ( root->next->next ), 50 );
    push( ( root->next->next ), 22 );
    push( ( root->next->next ), 19 );
  
    push( ( root->next->next->next ), 45 );
    push( ( root->next->next->next ), 40 );
    push( ( root->next->next->next ), 35 );
    push( ( root->next->next->next ), 20 );
  
   

    cout<<"Original Linked List is: "<<root;
    cout<<endl;

     // Let us flatten the list
    root = flatten(root);

    cout<<"The Flattening Of Linked List is: "<<root;

    return 0;
}