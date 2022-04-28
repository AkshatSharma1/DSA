#include<iostream>
#include"Node.cpp"
using namespace std;

// Two pointer approach
Node* intersectionPoint(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1!=ptr2){
        ptr1 = ptr1->next;
        ptr2=ptr2->next;

        if(ptr1==ptr2){
            return ptr1;
        }

        if(ptr1==NULL) ptr1 = head2;

        if(ptr2==NULL) ptr2= head1;
    }
    return ptr1;
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

    Node* ll = takeInput();

    // Sort the unsorted LL
    mergeSort(&ll);
    printList(ll);

    return 0;
}