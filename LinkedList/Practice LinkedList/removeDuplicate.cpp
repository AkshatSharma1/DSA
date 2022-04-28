#include<iostream>
#include"Node.cpp"
using namespace std;

// Remove duplicate from sorted linkedlist
void removeDuplicate(Node* head){
    Node* start = head;
    // Pointer to store next ptr of node to be deleted
    Node* double_next;

    if(start==NULL){ //list empty
        return;
    }

    // Traversal
    while(start->next!=NULL){
        if(start->data==start->next->data){
            double_next = start->next->next;
            delete(start->next);
            start->next = double_next;
        }
        else{
            // If no duplicates found
            start = start->next;
        }
    }
}

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

    // cout<<"print: \n";
    // printList(ll);
    // cout<<endl;

    // Data is changed in ll itself
    // insertNode(ll,3,100);

    // insertNode(ll,4,200);

    // Remove duplicates in sorted LL
    removeDuplicate(ll);
    printList(ll);

    return 0;
}