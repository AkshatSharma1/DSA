#include<iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertBST(node*root,int value)
{

    //if no value exists further,then return just root
    if(root==NULL)
    {
        return new node(value);
    }

    if(value < root->data)
    {
        root->left = insertBST(root->left,value);
    }
    else
    {
        root->right = insertBST(root->right,value);
    }
    return root;
}

node* build()
{
    int d;
    cin >> d;

    node*root = NULL;
    while(d!=-1){
        root = insertBST(root,d);
        cin>>d;
    }

    return root;
}

// Pair linked list class
class LinkedList{
    public:
        node* head;
        node* tail;
};

LinkedList flatten(node*root) {
    LinkedList l;

    if(root == NULL){
        l.head = NULL;
        l.tail = NULL;
    }

    //Case 1: leaf node
    if(root->left == NULL and root->right == NULL){
        l.head = root;
        l.tail = root;
        return l;
    }

    // Case 2: Left is not NULL
    if(root->left != NULL and root->right == NULL){
        LinkedList leftSide = flatten(root->left);
        leftSide.tail->right = root;
        
        l.head = leftSide.head;
        l.tail = root;

        return l;
    }

    // Case 3: Right is not NULL
    if(root->right != NULL and root->left == NULL)
    {
        LinkedList rightSide = flatten(root->right);
        rightSide.head->left = root; //or root->right = rightSide.head

        l.head = root;
        l.tail = rightSide.tail;

        return l;
    }

    // Case 4: Both are not NULL;
    LinkedList leftSide = flatten(root->left);
    LinkedList rightSide = flatten(root->right);

    leftSide.tail->right = root;
    rightSide.head->left = root; //or root->right = rightSide.head

    l.head = leftSide.head;
    l.tail = rightSide.tail;

    return l;
}

//inorder traversal
void InorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

int main()
{
    node* root = build();
    cout<<"Inorder traversal of BST is: ";
    InorderPrint(root);
    cout<<endl;
    cout<<endl;

    LinkedList l = flatten(root);
    node*temp = l.head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->right;
    }

    return 0;
}