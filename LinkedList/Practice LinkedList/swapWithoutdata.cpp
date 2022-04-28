#include<iostream>
#include<stack>
#include"Node.cpp"

using namespace std;

// Swap nodes by changing links
Node* swapLinks(Node* head, int x,int y){
    // first search the x and y in list and maintaincurr and prev ptrs

    // Special cases
    if(x==y) return head;

    // Seacch for x
    Node* prevX = NULL;
    Node* currX = head;

    while(currX!=NULL and currX->data!=x){
        prevX = currX;
        currX = currX->next;
    }

    // search for Y
    Node* prevY = NULL;
    Node* currY = head;

    while(currY!=NULL and currY->data!=y){
        prevY = currY;
        currY = currY->next;
    }

    // special cases
    // case 1: if either of x or y is not present
    if(currX==NULL or currY==NULL) return head;

    // Case2: if x is not head
    if(prevX!=NULL){
        prevX->next = currY;
    }
    else{
        // ?make y as new head
        head = currY;
    }

    // If y is not head
    if(prevY!=NULL){
        prevY->next = currX;
    }
    else{
        // ?make y as new head
        head = currX;
    }

    // Now swap the pointers
    Node* temp =currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return head;

}

void swap(Node* &a, Node* &b)
{
 
    Node* temp = a;
    a = b;
    b = temp;
}

// M-2: we can search for x and y in a single run and store theri ptr
void swapNOdesWithLinks(Node** head, int x,int y){
    // if same
    if(x==y) return;

    // Search
    Node** xData=NULL;
    Node** yData=NULL;

    while((*head)!=NULL){
        if((*head)->data==x){
            xData = head;
        }
        else if((*head)->data==y){
            yData = head;
        }

        head = &((*head)->next);
    }

    // if both x and y exists
    if(xData!=NULL and yData!=NULL){
        swap(*xData, *yData);
        swap(((*xData)->next), ((*yData)->next));
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

int main(){

    Node* head = takeInput();

    int x = 3;
    int y = 5;

    swapNOdesWithLinks(&head,x,y);
    printList(head);

    return 0;
}