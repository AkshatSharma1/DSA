#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
    public:
        node* left;
        node* right;
        int data;

        //constructor
        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree()
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

//BFS Traversal
void bfsTraversal(node* root)
{
    //base condition
    if(root==NULL)
    {
        return;
    }

    queue<node*> q;
    //initial
    q.push(root);
    //to check if level is completed or not
    q.push(NULL);

    while(!q.empty())
    {
        node* frontNode = q.front();
        q.pop();

        //check if frontNode is null or no
        if(frontNode!=NULL)
        {
            cout<<frontNode->data<<" ";

            //recursive part

            //if left child exists
            if(frontNode->left)
            {
                q.push(frontNode->left);
            }

            //if right child exists
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        else if (frontNode==NULL)
        {
            q.push(NULL);
            
        }

    }
    return;
}

//Build height balanced build
node*buildFromArray(int*a ,int s,int e)
{
    //base case
    if(s>e) return NULL;

    int mid = (s+e)/2;

    node* root = new node(a[mid]);
    root->left = buildFromArray(a,s,mid-1);
    root->right = buildFromArray(a,mid+1,e);

    return root;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int n=7;

    node* root = buildFromArray(a,0,n-1);

    bfsTraversal(root);

    return 0;
}