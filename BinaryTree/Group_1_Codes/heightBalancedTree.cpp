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
            cout<<endl;
        }

    }
    return;
}

//Height Balanced Tree Check
//Method-1: Using pair
// class HBpair{
//     public:
//         int ht;
//         bool balanced;
// };

// HBpair isBalanced(node*root)
// {
//     HBpair p;
//     if(root==NULL)
//     {
//         p.ht = 0;
//         p.balanced = true;
//         return p;
//     }

//         //recursive case 
//         HBpair left = isBalanced(root->left);
//         HBpair right = isBalanced(root->right);

//         p.ht = max(left.ht, right.ht) + 1;

//         if(abs(left.ht - right.ht)<=1 and left.balanced and right.balanced)
//         {
//             p.balanced = true;
//         }
//         else
//         {
//             p.balanced = false;
//         }
//         return p;
// }
    
//Method-2: Using height as a pointer 
bool isBalanced(node*root, int* height)
{
    if(root==NULL)
    {
        return true;
    }

    int lh=0,rh=0;
    if(isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if(isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else
    {
        return false;
    }
}


int main(){
    node* root = buildTree();

    cout<<endl;
    // if(isBalanced(root).balanced)
    // {
    //     cout<<"Balanced Tree";
    // }
    // else
    // {
    //     cout<<"Not Balanced";
    // }

    // return 0;

    int height = 0;
    if(isBalanced(root,&height)==true)
    {
        cout<<"Balanced Tree";
    }
    else
    {
        cout<<"Notbalanced";
    }
    return 0;

}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1