// BFS Traversal using queues. 
// Here I am making a function to add node one by one 

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

// Utility function to create a new tree node
node* newNode(int d)
{
    node *temp = new node(d);
    // temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void bfsTraversal(node*root)
{
    queue<node*> q; //int should not be used bcoz we want to know its children and by taking only data like int we cant know what are its children. So we will use node or node* instead
    //push root first 
    q.push(root);

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

int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(8);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(9);
    root->left->right->right = newNode(7);
    //right subtree
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
 
    cout << "Level Order traversal of binary tree is \n";
    bfsTraversal(root);
    return 0;
}