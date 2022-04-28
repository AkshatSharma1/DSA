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

node*searchBST(node*root,int key)
{
    //base casee
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(root->data > key)
    {
        //search in left
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
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

//Delete in BST
node* deleteInBST(node*root,int key)
{
    //search node which is to be deleted
    if(key < root->data)
    {
        root->left = deleteInBST(root->left,key);
    }

    else if(key > root->data)
    {
        root->right = deleteInBST(root->right,key);
    }

    else//key==root->data
    {   
        //Case1: Node with 0 children(leaf node)
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //case 2: Node having only one child
        if(root->left == NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL and root->left!=NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        //Case 3: Node with 2 children
        //find inorder successor from right subtree
        node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right,temp->data);
    }

    return root;
}

void bfsTraversal(node*root)
{
    queue<node*> q; //int should not be used bcoz we want to know its children and by taking only data like int we cant know what are its children. So we will use node or node* instead
    //push root first 
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        //take the data into consideration not node, so here q.front will give node 
        node* frontNode = q.front();

        if(frontNode == NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<frontNode->data<<" ";
            q.pop();
            //if left child is true that it exists
            if(frontNode->left)
            {
                q.push(frontNode->left);
            }

            //if right child is true that it exists
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }

        }
        
    }
    return;
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
    //use for direct insert by passing value
    // node* root = NULL;
    // root = insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);

    //use when all inputs at a time like 5 1 3 4 2 7 -1, -1 for ending
    node*root = build();
    cout<<"Inorder traversal is: ";
    InorderPrint(root);
    cout<<endl;

    // cout<<"BFS traversal is: \n";
    // bfsTraversal(root);

    // if(searchBST(root,5) == NULL)
    // {
    //     cout<<"Key doesnot exist";
    // }
    // else
    // {
    //     cout<<"Key exist in BST";
    // }


    root = deleteInBST(root,5);

    cout<<"Inorder traversal after deleting a node is: ";
    InorderPrint(root);
    cout<<endl;

    return 0;
}

// Input: 5 1 3 4 2 7 -1
//Output:
// Inorder traversal is: 1 2 3 4 5 7 
// BFS traversal is: 5 1 7 3 2 4    