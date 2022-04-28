#include<iostream>
#include <vector>
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

// Utility function to create a new tree node
node* newNode(int d)
{
    node *temp = new node(d);
    // temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void flatten(node* root)
{
    //base condition: if root is null
    if(root==NULL or (root->left==NULL && root->right==NULL))
    {
        return;
    }

    //now we have to recursively flat left and right subtree if root!=Null
    //first chk if left sub tree is not null
    if(root->left!=NULL)
    {
        flatten(root->left);

        node* temp = root->right;
        //now exchange left and right subtree
        root->right = root->left; //root-> left whichwe obtained from flatten(root->left)
        root->left = NULL;

        //find tail of right subtree
        node*t = root->right;//tail of right finding
        while(t->right!=NULL)
        {
            t = t->right;
        }

        t->right = temp;

        flatten(root->right);

    }

}

void inOrderPrint(node* root)
{
   if(root==NULL) return;

    inOrderPrint(root->left);
    cout<<root->data<<"->";
    inOrderPrint(root->right);
}

int main()
{
    node* root = new node(4);
    root->left = new node(9);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    flatten(root);

    inOrderPrint(root);

    return 0;
}