#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        // node*root;
        node*left;
        node*right;

        //constructor
        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree() //returns the address of root
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;

}

//Preorder traversal and print tree
void preorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//Inorder traversal and print tree
void InorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

//Postorder traversal and print tree
void postorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

//count of nodes
int countOfNodes(node*root)
{
    if(root == NULL) return 0;

    return 1 + countOfNodes(root->left) + countOfNodes(root->right);
}

//sum of nodes
int sumOfNodes(node* root)
{
    if(root == NULL) return 0;

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main()
{
    node* root = buildTree();

    cout<<endl;
    cout<<"Count of Nodes is:"<<" "<<countOfNodes(root);

    cout<<endl;
    cout<<endl;
    cout<<"Sum of all Nodes of binary tree is:"<<" "<<sumOfNodes(root);

    return 0;
}