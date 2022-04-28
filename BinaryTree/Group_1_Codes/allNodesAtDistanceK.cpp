#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
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

// node* levelOrderBuild()
// {
//     // enter data
//     int d;
//     cin>>d;

//     node*root = new node(d);
//     queue<node*> q;
//     q.push(root);

//     while(!q.empty())
//     {
//         node* curr = q.front();
//         q.pop();

//         int c1,c2;//children left and right
//         // input children
//         cin>>c1>>c2;
//         if(c1!=-1)
//         {
//             curr->left = new node(c1);
//             q.push(curr->left);
//         }
//         if(c2!=-1)
//         {
//             curr->right = new node(c2);
//             q.push(curr->right);
//         }

//     }
//     return root;
// }

void levelOrderPrint(node*root)
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

// istream& operator>>(istream&is, node*&root)
// {
//     levelOrderBuild(root);
//     return is;
// }

// ostream& operator<<(ostream&os,node*&root)
// {
//     levelOrderPrint(root);
//     return os;
// }

// void printAtLevelK(node*root,int k)
// {
//     if(root==NULL) return;

//     //if level starts from 0 then
//     if(k==0)
//     {
//         cout<<root->data<<" ";
//         return;
//     }

//     //rec left and right child call
//     printAtLevelK(root->left, k-1);
//     printAtLevelK(root->right, k-1);
    
//     return;
// }

// int printAtDistanceK(node*root, node*target, int k)
// {
//     //base case:
//     if(root==NULL)
//     {
//         return -1;
//     }

//     //target reached 
//     if(root==target)
//     {
//         printAtLevelK(target,k);
//         return 0;
//     }

//     //going back to ancestor nodes
//     int dl = printAtDistanceK(root->left, target, k);

//     if(dl!=-1)
//     {
//         /*two cases:
//         a) If ancestor is the printing node 
//         b)Need to go to the right ancestor node
//         */
//         if(dl+1==k)
//         {
//             cout<<root->data<<" ";
//         }
//         else//go to right ancestor
//         {
//             printAtLevelK(root->right,k-2-dl);
//         }
//         return 1+dl;
//     }

//     int dr = printAtDistanceK(root->right, target,k);
//     if(dr!=-1)
//     {
//         if(dr+1==k)
//         {
//             cout<<root->data<<" ";
//         }
//         else
//         {
//             printAtLevelK(root->left,k-2-dr);
//         }
//         return 1+dr;
//     }
//     return -1;
// }

//Case 1: Node subtree 
void printSubtreeNodes(node *root,int k)
{
    if(root==NULL)
    {
        return;
    }

    //if total distance covered from curr njode to target node
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

//Case 2: return distance till node's ancestor so that it finds for target node from ancestor with distnace k-ancestor ditnce from given node
int printNodesAtK(node *root,node*target, int k)
{
    if(root==NULL)
    {
        return -1;
    }

    //if only root is the ancestor and taregt node i.e distnace from curr to ancestor =0
    if(root==target)
    {
        printSubtreeNodes(root,k);
        return 0;//distance = 0 since target = ancestor
    }

    //find ancestor for left subtree
    int dl = printNodesAtK(root->left,target,k);
    if(dl!=-1) //means no target in left
    {
        /*two cases:
        a) If ancestor is the printing node 
        b)Need to go to the right ancestor node
        */
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else//go to right ancestor
        {
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    //for ancestpr in right
    int dr = printNodesAtK(root->right, target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

int main()
{

    // node*root = levelOrderBuild();

    //take input tree nodes
    // cin>>root;
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);


    node*target = root->left;

    //level order print
    // cout<<root<<endl;
    levelOrderPrint(root);


    printNodesAtK(root,target,1);

    return 0;
}

/* here
    if the nodes which are to be found at k distance
    from target nodes are present in the subtree of the target root node,
     then we will use simple (print at level k) function
*/

/*else
    we will make a function to print nodes at k distance from target node outside of subtree
*/    