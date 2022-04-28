#include<iostream>
#include<unordered_map>
#include "Node.cpp"
using namespace std;

bool detectLoop(Node* head)
{
    Node*slow=head;
    Node*fast=head;
    while(slow!=NULL and fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}

// Find length of loop in Linked List
// Use simple count nodes function or write code inside the lengthLoop function only
int lengthNodes(Node* head){
    Node* temp=head;
    int count=0;
    // Count till the temp reaches staring point
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    return count;
}

// Detect loop and count nodes
int loopNodes(Node* head){
    Node*slow=head;
    Node*fast=head;
    while(slow!=NULL and fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return lengthNodes(slow);
        }
    }
    return 0;
}

// Remove loop 
// Simple way - use hashing(check if the node already present in the hashmap if present then make the node just one behind it point to NULL)
void hashRemove(Node* head){
    // Create a hashmap to store nodes while visiting
    unordered_map<Node*, int> visited;

    // Pointer for checking the last node
    Node* last = NULL;
    while(head!=NULL){
        // While traversing if not present them add
        if(visited.find(head)==visited.end()){
            visited[head]++;
            last = head;
            head=head->next;
        }

        // if present the last point to NULL
        else{
            last->next = NULL;
            break;
        }
    }
}

// M-2: Counting nodes and then removing
void removeLoop(Node* nodeInLoop, Node* head){
    Node* ptr1 = nodeInLoop;
    Node* ptr2 = nodeInLoop;

    // count
    int count = 1;
    while(ptr1->next!=ptr2){
        ptr1 = ptr1->next;
        count++;
    }

    // ?one ptr1 to head
    ptr1 = head;
    ptr2 = head;

    // Pointer to count nodes after head
    for(int i=0;i<count;i++){
        ptr2 = ptr2->next;
    }

    while(ptr2!=ptr1){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get the ptr to laast node and fix it to NULL
    while(ptr2->next!=ptr1){
        ptr2 = ptr2->next;
    }

    ptr2->next = NULL;
}

// Method 3: Withount counting nodes
void detectRemove(Node* head){
    Node* slow = head;
    Node* fast = head;

    // If no loop or empty
    if(head==NULL or head->next==NULL){
        return;
    }

    while(slow!=NULL and fast!=NULL and fast->next!=NULL){

        // Detection of loop
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)//loop found
        {
            break;
        }
    }

    // If loop
    if(slow==fast){
        slow=head;

        // If head node is start of loop
        if(slow==fast){
            while(fast->next!=slow){
                fast = fast->next;
            }
        }

        else{
            while(slow->next!=fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = NULL;
    }
}

// Find first node in loop
Node* detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    // If loop does not exist
    if (slow != fast)
        return NULL;
 
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
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

    // Adding cycle
    ll->next->next->next->next->next = ll->next->next;

    // loop detect
    if(detectLoop(ll)){
        cout<<"\n Loop Found.";
    }
    else{
        cout<<"No loop";
    }

    // Count nodes in loop
    cout<<"\nNodes in Loop: "<<loopNodes(ll);

    // After Removing print
    detectRemove(ll);
    cout<<endl;
    printList(ll);

    return 0;
}