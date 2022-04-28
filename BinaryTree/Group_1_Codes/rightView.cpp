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

// Right view using dfs traversal(root->right->left)
void printRightView(node*root,int level,int &maxLevel) //here reference used as we dont want to store copies of maxlevel
{
    if(root==NULL)
    {
        return;
    }

    if(level>maxLevel)
    {
        // new level is reached
        cout<<root->data<<" ";
        maxLevel=level;
    }

    //Now traverse right and left
    printRightView(root->right,level+1,maxLevel);
    printRightView(root->left,level+1,maxLevel);

    return;
}

// Method 2: USING BFS Traversal
void rightView(node *root)
{
    if(root==NULL)
    {
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty())
    {
        //finding nodes in queue
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            node*curr = q.front();
            q.pop();

            //if right side child i.e, back of queue
            if(i == n-1)
            {
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

//left view 
void leftView(node *root)
{
    if(root==NULL)
    {
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty())
    {
        //finding nodes in queue
        int n = q.size();
        for(int i=0;i<n;i++)//queue index from 0
        {
            node*curr = q.front();
            q.pop();

            //if left side child i.e, front of queue
            if(i == 0) //i==1 if queue index from 1
            {
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
  
    node*root = buildTree();
    // fopen("input.txt", "r");
    // fopen("output.txt", "w");

    // cout<<root<<endl;
    // int maxLevel = -1;
    cout<<"Right View is:"<<endl;
    // printRightView(root,0,maxLevel);

    rightView(root);

    cout<<"\nLeft View is:"<<endl;
    leftView(root);

    return 0;

}