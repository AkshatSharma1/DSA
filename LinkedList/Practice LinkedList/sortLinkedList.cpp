// Merge sort is used for sorting linkedlist if time constraint is O(nlogn) and space constraint is O(1).
#include<iostream>
#include"Node.cpp"
using namespace std;

// Merge function
Node* merge(Node* left, Node* right);

// get mid
void getMid(Node* curr, Node** left, Node** right){
    Node* slow = curr;
    Node* fast = curr;

    while(fast->next!=NULL and fast->next->next!=NULL){
        slow =slow->next;
        fast = fast->next->next;
    }

    *left = curr;
    *right = slow->next;
    slow->next=NULL;
}

// Sorting function
void mergeSort(Node** head){
    Node* curr = *head;
    Node* left;
    Node* right;

    if(curr==NULL or curr->next==NULL) return;

    // get mid
    getMid(curr, &left, &right);

    // call sort
    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}

Node* merge(Node* left, Node* right){
    Node* dummyHead = NULL;

    // if right null
    if(!right){
        return left;
    }
    else if(!left){
        return right;
    }

    if(left->data<=right->data){
        dummyHead = left;
        dummyHead->next = merge(left->next, right);
    }
    else{
        dummyHead = right;
        dummyHead->next = merge(left, right->next);
    }

    return dummyHead;
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
    // removeDuplicate(ll);

    // Sort the unsorted LL
    mergeSort(&ll);
    printList(ll);

    return 0;
}

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//             return head;
        
//         ListNode* slow = head;
//         ListNode* fast = head->next;
        
//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         //divide the list into two parts 
//         fast = slow->next;
//         slow->next = NULL;
        
//         return merge(sortList(head), sortList(fast));
//     }
    
//     ListNode* merge(ListNode* l1, ListNode* l2)
//     {
//         ListNode dump(0);
//         ListNode* cur = &dump;
        
//         while (l1 != NULL && l2 != NULL)
//         {
//             if (l1->val < l2->val)
//             {
//                 cur->next = l1;
//                 l1 = l1->next;
//             }
//             else
//             {
//                 cur->next = l2;
//                 l2 = l2->next;
//             }
                
//             cur = cur->next;
//         }
        
//         if (l1 != NULL)
//             cur->next = l1;
//         else
//             cur->next = l2;
            
//         return dump.next;
//     }
// };