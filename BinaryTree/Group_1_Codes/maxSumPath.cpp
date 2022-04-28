#include<iostream>
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

class Pair{
    public:
        int branchSum;
        int maxSum;
    Pair()
    {
        branchSum = 0;
        maxSum = 0;
    }

};

Pair maxSumPath(node* root)
{
    Pair p;

    if(root == NULL)
    {
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    //options
    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = root->data + left.branchSum + right.branchSum;

    int curr_ans_thr_root = max(op1,max(op2,max(op3,op4)));

    p.branchSum = max(left.branchSum,max(right.branchSum,0)) + root->data;
    p.maxSum = max(left.branchSum,max(right.branchSum,curr_ans_thr_root));

    return p;
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    cout<<"Max Sum Path is: "<<maxSumPath(root).maxSum<<endl;

    return 0;
}