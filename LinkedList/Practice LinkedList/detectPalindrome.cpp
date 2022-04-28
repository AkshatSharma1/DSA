#include<iostream>
#include<stack>
#include"Node.cpp"

using namespace std;

bool checkPal(Node** left, Node* right){
    // Base case
    if(right == NULL){
        return true;
    }

    // checking if the sublist is palindrome or not
    bool subList = checkPal(left, right->next);

    if(!subList) return false;

    // else
    bool checkVal = (right->data == (*left)->data);

    *left = (*left)->next;

    return checkVal;

}

// Using Stack
bool isPalindrome(Node* head){
    Node* first = head;
    stack<int> s;

    // While traversing push the node data into the stack
    while(first->next!=NULL){
        s.push(first->data);
        first = first->next;
    }

    // Now again trvaerse the list 
    Node* second = head;
    while(second->next!=NULL){
        
        // get the stack top
        int top = s.top();
        s.pop();

        if(second->data != top){
            return false;
        }

        second = second->next;
    }
    return true;

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

    if(checkPal(&head, head)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    

    return 0;
}