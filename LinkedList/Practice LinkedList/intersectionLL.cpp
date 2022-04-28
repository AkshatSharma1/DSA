#include<iostream>
#include<stack>
#include"Node.cpp"

using namespace std;

// NOde *findinterssection nodes
Node* commonPts(Node* head1, Node* head2){
    // Dummy node for storingg res
    Node* dummy = new Node(0);
    Node* curr = dummy;
    Node* temp1 = head1, *temp2 = head2;

    while(temp1 and temp2){
        if(temp1->data==temp2->data){
            Node* newNode = new Node(temp1->data);
            curr->next = newNode;
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }

        else if(temp2->data < temp1->data){
            temp2 = temp2->next;
        }
    }

    return dummy->next;
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

    Node* sec = takeInput();

    Node* res = sortedIntersect(head, sec);

    printList(res);


    return 0;
}