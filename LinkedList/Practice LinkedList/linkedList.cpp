// Create a Linked List of nodes
#include<iostream>
using namespace std;

// Including node class
#include "Node.cpp"


// taking input of nodes until -1 is found
Node* takeInput(){
    int data;
    cin>>data;

    // initialising head with Null
    Node* head=NULL;
    Node* tail = NULL; //keeping track of new node added 

    while(data!=-1)
    {
        Node *newNode = new Node(data);
    // Check if it is the first node
        if(head==NULL)
        {
            head= newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next; //or tail = newNode;
        }
        // Taking data
        cin>>data;
    }

    return head;
}

// Insert at ith position
// Iterative way
Node* insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node* temp = head;

    // if i=0 means insert at head
    if(i==0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    while(temp!=NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    
    if(temp!=NULL) //if i lies in range of list
    {
        Node* a = temp->next; //storing the node after ith pos
        temp->next = newNode;
        newNode->next = a;
    }

    // and if i does not lie inside the length then do nothing

    return head;
}

// insert recursively at ith
Node* insertNodeRec(Node* head, int i, int data)
{
    // Base case
    if(head==NULL){
        return NULL;
    }
    if(i==0){
        Node*temp = new Node(data);
        temp->next = head;
        return temp;
    }
    if(i==1) //2nd pos and onward
    {
        Node* temp = new Node(data);
        temp->next = head->next;
        head->next = temp;
        return head;
    }

    Node* curr = insertNodeRec(head->next,i-1,data);

    return head;
}

// Delete Node
Node* deleteNOde(Node* head, int i)
{
    // If head is to be deleted
    if(i==0)
    {
        return head->next;
    }

    // If empty list
    if(head==NULL)
    {
        return head;
    }

    // if pos i lies not in range
    if(i<0){
        return head;
    }

    Node* temp = head;
    int count = 0;

    while(temp!=NULL && count<i-1){
        temp = temp->next;
        count++;
    }

    // chk if current Node is tail or not
    if(temp==NULL || temp->next==NULL)
    {
        return head;
    }

    // else
    temp->next = temp->next->next;

    return head;
}

// Delete Node rec
Node* deleteNodeRec(Node* head, int i){
    // Base case
    if(head->next==NULL) //only no node
    {
        return NULL;
    }

    if(i==0){
        Node* temp = head->next;
        head->next=NULL;
        delete head;
        return temp;
    }

    if(i==1){
        Node* temp = head->next;
        head->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    // rec call
    Node* curr = deleteNodeRec(head->next,i-1);
    return head;
}

// Print the length of ll
int length(Node*head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

// Find the ith node
int search(Node*head,int i)// no &head as we only want to search through values
{
    int count = 0;
    //Traversing
    while(head!=NULL)
    {
        if(count==i)
        {
            return head->data;
        }
        else{
            head=head->next;
            count++;
        }
    }
    return 0;
}

// Mid point of a linked list
Node* printMid(Node* head){
    // take two pointers
    Node *slow = head;
    Node *fast = head;

    // do only if head!=NULL
    if(head!=NULL)
    {
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 
    }

    return slow;
}

void printList(Node* head){
    Node* temp = head;  
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}



int main()
{
    // Staticaly creating a node object
    // Node n1(1); // data=1
    // Node n2(2);

    Node* ll = takeInput();

    cout<<"print: \n";
    printList(ll);
    cout<<endl;

    // Data is changed in ll itself
    insertNodeRec(ll,3,100);
    printList(ll);
    cout<<endl;

    insertNodeRec(ll,4,200);
    printList(ll);
    cout<<endl;

    Node* afterDeletion = deleteNOde(ll,2);
    printList(ll);
    cout<<endl;
    // printList(afterDeletion);

    int lengthOfLL = length(afterDeletion);
    cout<<endl;
    cout << lengthOfLL;

    // Print 2nd node data
    int nodeData = search(afterDeletion, 2);
    cout<<"\n"<<nodeData; // 0 means not found

    // Print mid
    Node* mid = printMid(ll);
    cout<<"\n"<<mid->data;

    return 0;
}