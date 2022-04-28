// Code to calculate CATALAN Series
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

int catalan(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) 
    //here i starting from 1 to N. 
    // Also it can be
    // for(int i=0;i<n;i++)
    // {
    //     ans += catalan(i)*1*catalan(n-i-1);
    // }

    {
        ans += catalan(i-1)*1*catalan(n-i);
    }

    return ans;
}

//Application 1: Find total no of BST's
vector<node*> constructBST(int start, int end) {
    vector<node*> trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++) {
        vector<node*> leftSubTree = constructBST(start,i-1);
        vector<node*> rightSubTree = constructBST(i+1,end);

        for(int j=0;j<leftSubTree.size();j++) {
            node* left = leftSubTree[j];
            for(int k=0;k<rightSubTree.size();k++) {
                node* right = rightSubTree[k];

                node* Node = new node(i);
                Node->left = left;
                Node->right = right;

                trees.push_back(Node);
            }
        }
    }
    return trees;
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
    // cout<<"Catalan Series is: ";
    // for(int i=0;i<10;i++)
    // {
    //     cout<<catalan(i)<<" ";
    // }
    // cout<<endl;

    vector<node*> totalTrees = constructBST(1,3);

    for(int i=0;i<totalTrees.size();i++)
    {
        cout<<(i+1)<<" : ";
        preorderPrint(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}