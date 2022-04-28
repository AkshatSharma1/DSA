#include<iostream>
#include <vector>
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

// Utility function to create a new tree node
node* newNode(int d)
{
    node *temp = new node(d);
    // temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// bool getPath(node* root,int key, vector<int> &path) //key is node upto which path is to be checked
// {
//     //base case
//     if(root==NULL)
//     {
//         return false;
//     }

//     // assuming that the path being travelled is correct
//     path.push_back(root->data);


//     if(root->data == key)
//     {
//         return true;
//     }

//     // else
//     //traverse in left subtree or right subtree
//     if(getPath(root->left,key,path) or getPath(root->right,key,path))
//     // if left subtree returns false then call on right subtree
//     {
//         return true;
//     }

//     //if key not exists in l or r s.t of current or current root is not key
//     path.pop_back();
//     return false;

// }

// int LCA(node* root,int n1,int n2) //n1 and n2 are node1 and node 2 data respectively
// {
//     //vector for path 
//     vector<int> path1;
//     vector<int> path2;

//     if(!getPath(root,n1,path1) or !getPath(root,n2,path2))
//     {
//         //path doesnot exist from either root to n1 or n2
//         return -1;//lca doesnot exist
//     }

//     int pc; //path change
//     for(pc = 0; pc<path1.size() and path2.size(); pc++)
//     // check for path change i.e pc value at path1 != pc value at path2
//     {
//         if(path1[pc]!=path2[pc])
//         {
//             break;
//         }
//     }

//     return path1[pc-1];
// }

//The above method has very bad time complexity as we are traversing same node multiple times either for lca or getPath

//Method 2: 
// single traversal on node

node* lca2(node*root,int n1,int n2)
{

    //base case:
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->data == n1 or root->data == n2)
    {
        return root;
    }

    //returns lca from left subtree from nodes n1 and n2
    node* leftLCA = lca2(root->left,n1,n2);

    //returns lca from right subtree from nodes n1 and n2
    node* rightLCA = lca2(root->right,n1,n2);

    //Now if both the leftLCA and rightLCA has same node then that node is the LCA
    if(leftLCA && rightLCA)
    {
        return root;
    }

    if(leftLCA!=NULL)//means right one is null that is lca doesnot exist in right subtree
    {
        return leftLCA;
    }

    return rightLCA;

}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);

    int n1 = 7;
    int n2 = 6;

    node* lca = lca2(root,n1,n2);

    if(lca == NULL)
    {
        cout<<"LCA doesnot exist";
    }
    else
    {
        cout<<"LCA: "<<lca->data<<endl;
    }

    return 0;
}