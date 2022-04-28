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
        // q.pop();

        //check if frontNode is null or no
        if(frontNode==NULL)
        {
            cout<<","<<endl;
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

    }
    return;
}

//Build from preorder and inorder
node* createTree(int *pre,int* in,int s,int e)
{
    static int i=0;
    //base case:
    if(s>e)
    {
        return NULL;
    }

    //rec case
    node* root = new node(pre[i]);
    int index = -1;

    //search for curr index in inorder
    for(int j=s;j<=e;j++)
    {
        if(pre[i]==in[j])
        {
            index = j;
            break;
        }
    }
    
    i++;
    root->left = createTree(pre,in,s,index-1);
    root->right = createTree(pre,in,index+1,e);

    return root;
} 

int main()
{
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);

    node*root = createTree(pre,in,0,n-1);
    bfsTraversal(root);

    return 0;
}