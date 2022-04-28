#include<bits/stdc++.h>
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

node* constructBSTFromPreorder(int preorder[],int* pIndex,int key,int mini,int maxi,int n)
{

    //base case 
    if(*pIndex >= n)
    {
        return NULL;
    }
    node*root = NULL;
    //if key satisifies (min,max) condition then make key as root, else
    if(key > mini and key < maxi)
    {
        root = new node(key);
        *pIndex = *pIndex + 1;

        //chek for all values in preorder array
        if(*pIndex < n)
        {
            root->left = constructBSTFromPreorder(preorder,pIndex,preorder[*pIndex],mini,key,n);
        }
        if(*pIndex < n)
        {
            root->right = constructBSTFromPreorder(preorder,pIndex,preorder[*pIndex],key,maxi,n);
        }
    }

    // else if key donot satisfies min and max condition then
    return root;
}

// Check for bst 
bool isBST(node* root,int mini,int maxi)
{
    if(root==NULL) return true;

    if(root->data >= mini and root->data <= maxi and isBST(root->left,mini,root->data) and isBST(root->right,root->data,maxi))
    {
        return true;
    }

    return false;
}

//inorder successor
node* inorderSuccessor(node* root)
{
    node*curr = root;
    while(curr and curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}

//preorder print
void preorderPrint(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int preorder[] = {10,2,1,13,11};
    int n=5;
    int pIndex = 0;
    node* root = constructBSTFromPreorder(preorder,&pIndex,preorder[0],INT_MIN,INT_MAX,n);
    preorderPrint(root);
    if(isBST(root,INT_MIN,INT_MAX))
    {
        cout<<"\n\nThe tree is a BST.";
    }
    else
    {
        cout<<"Not a BST";
    }

    
    return 0;
}