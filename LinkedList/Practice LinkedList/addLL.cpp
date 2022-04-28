#include <iostream>
#include <stack>
#include "Node.cpp"

using namespace std;

// Reversing a linked list
// M1: iterative(using more pointers)
Node *revLL(Node *head)
{
    // make next and prev as null
    Node *prev = NULL;
    Node *next = NULL;

    Node *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addLL(Node *l1, Node *l2)
{

    // Rev the both ll
    l1 = revLL(l1);
    l2 = revLL(l2);

    // Ptrs to store info
    int carry = 0;
    int sum = 0;
    Node *temp; // to take i/p added val
    Node *result = NULL;
    Node *curr = NULL; // for traversal in result;

    while (l1!=NULL || l2!=NULL)
    {
        sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        // store result of addition
        temp = new Node(sum);

        // if temp is first node(head)
        if (result == NULL)
        {
            result = temp;
        }
        else
        {
            curr->next = temp;
        }

        curr = temp;

        // if l2 empty
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    // Now in special case when carry is left after addition as in 99 + 1 =100 (here 1 is left in carry)
    if (carry>0)
    {
        temp = new Node(carry);
        curr->next = temp;
        curr = temp;
    }

    // now reverse the result
    result = revLL(result);

    return result;
}

// taking input of nodes until -1 is found
Node *takeInput()
{
    int data;
    cin >> data;

    // initialising head with Null
    Node *head = NULL;
    Node *tail = NULL; // keeping track of new node added

    while (data != -1)
    {
        Node *newNode = new Node(data);
        // Check if it is the first node
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next; // or tail = newNode;
        }
        // Taking data
        cin >> data;
    }

    return head;
}

// Insert at ith position
// Iterative way
Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    // if i=0 means insert at head
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) // if i lies in range of list
    {
        Node *a = temp->next; // storing the node after ith pos
        temp->next = newNode;
        newNode->next = a;
    }

    // and if i does not lie inside the length then do nothing

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = takeInput();
    Node *head2 = takeInput();

    // cout << endl;
    // head = revLL(head);
    // printList(head);

    // cout<<endl;
    // head2 = revLL(head2);
    // printList(head2);
    Node *newLL = addLL(head, head2);
    printList(newLL);

    return 0;
}