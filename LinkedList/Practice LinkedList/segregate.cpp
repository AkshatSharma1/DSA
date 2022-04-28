#include <iostream>
// #include "Node.cpp"

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // Constructor
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

int getNthFromLast(struct Node *head, int n)
{
    // Two pointer approach
    struct Node* slow = head;
    struct Node* fast = head;
    
    for(int i=0;i<n;i++){
        if(fast==NULL){
            return -1; //n is > length
        }
        fast = fast->next;
    }
    
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

Node *divide(Node *head)
{
    // code here
    // Base case
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = curr;
    Node *firstOdd = head;
    Node *prevFirstOdd;

    while (curr != NULL)
    {
        if ((curr->data % 2) || ((firstOdd->data % 2) == 0))
        { // if no odd element

            // do nothing
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (firstOdd == head)
            {
                prev->next = curr->next;
                curr->next = firstOdd;
                head = curr;
                prevFirstOdd = curr;
                curr = prev->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = firstOdd;
                prevFirstOdd->next = curr;
                prevFirstOdd = curr;
                curr = prev->next;
            }
        }

        if (firstOdd->data % 2 == 0)
        {
            prevFirstOdd = firstOdd;
            firstOdd = firstOdd->next;
        }
    }
    return head;
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

    Node* newLL =  divide(head);

    printList(newLL);

    return 0;
}