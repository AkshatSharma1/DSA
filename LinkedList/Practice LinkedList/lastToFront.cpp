#include<iostream>
#include<string>
#include<typeinfo>
#include"Node.cpp"
using namespace std;

void lastToFront(Node **head){
    // If empty or only one
    if(*head==NULL or (*head)->next==NULL) return;

    // Node to store 2nd last
    Node* secLast = NULL;
    // temp ptr to traverse
    Node* temp = *head;

    while(temp->next!=NULL){
        // ?second last
        secLast = temp;
        temp = temp->next;
    }

    // Now make secLast as last
    secLast->next = NULL;

    // Make last point to head
    temp->next = *head;
    *head = temp;
}

void addOne(Node* head){
    // If only one or none
    string s;
    while(head!=NULL){
        s.append(to_string(head->data));
        head = head->next;
    }

    int num = stoi(s);
    cout<<num;
    cout<<endl;
    // cout<<typeid(num).name();

    // add one
    cout<<num+1<<endl;

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

    // Last to front
    // lastToFront(&ll);
    // printList(ll);

    addOne(ll);

    return 0;
}