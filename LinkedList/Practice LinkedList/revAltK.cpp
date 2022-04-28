#include<iostream>
#include<stack>
#include"Node.cpp"

using namespace std;

// Rev k digits
Node* rev(Node* head, int k){
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    int kCount = 0;

    // Base case
    if(head==NULL) return NULL;

    while(curr!=NULL && kCount<k){
        // change ptrs 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        kCount++;
    }

    // we want to skip next k nodes
    int count = 0;
    //Now change the head to k+1 node
    if(head!=NULL){
        head->next = curr;
    } 

    //skip alt k nodes
    while(count<k-1 && curr!=NULL){
        curr=curr->next;
        count++;
    }

    //rec call on alt k nodes
    if(curr!=NULL){
        curr->next = rev(curr->next, k);
    }
    return prev; //new head

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

int main(){

    Node* head = takeInput();

    cout<<endl;
    Node* newLL = rev(head, 2);
    printList(newLL);

    return 0;
}