#include<iostream>
#include<queue>
// #include<pair>
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

//Reaplace sum
int replaceSum(node* root)
{
    if(root == NULL) return 0;

    if(root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    //Recursion
    int lsum = replaceSum(root->left);
    int rsum = replaceSum(root->right);

    int temp = root->data;
    root->data = lsum+rsum;

    return temp + root->data;
}

void bfsTraversal(node*root)
{
    if(root==NULL) return;
    queue<node*> q; //int should not be used bcoz we want to know its children and by taking only data like int we cant know what are its children. So we will use node or node* instead
    //push root first 
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        //take the data into consideration not node, so here q.front will give node 
        node* frontNode = q.front();
        q.pop();

        if(frontNode!=NULL)
        {
            cout<<frontNode->data<<" ";

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

        else if(!q.empty())//if not empty
        {
            q.push(NULL);
            cout<<endl;
        }

    }
    return;
}

int main()
{
    node* root = buildTree();

    cout<<endl;
    cout<<"Bfs traversal before replace sum is: "<<endl;
    bfsTraversal(root);

    cout<<endl;
    replaceSum(root);
    cout<<"Bfs traversal after replace sum is: "<<" ";
    cout<<endl;
    bfsTraversal(root);

    return 0;
}