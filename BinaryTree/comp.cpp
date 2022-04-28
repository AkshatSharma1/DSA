// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
class node{
    public:
        string data;
        node*left;
        node*right;

        node(string d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertBST(node*root,string value)
{

    //if no value exists further,then return just root
    if(root==NULL)
    {
        return new node(value);
    }

    if(value < root->data)
    {
        root->left = insertBST(root->left,value);
    }
    else
    {
        root->right = insertBST(root->right,value);
    }
    return root;
}

node* build(int n)
{
    string d;
    cin >> d;

    node*root = NULL;
    for (int i = 0; i < n-1;i++)
    {
        if(d=="null")
        {
            break;
        }
        else
        {
            root = insertBST(root,(d));
            cin>>d;
        }
    }

    return root;
}

// Function for in-order traversal of the tree
void inorder(node* curr, node*& prev, int& ans)
{

	// Base-case
	if (curr == NULL)
		return;

	// Calling in-order on the left sub-tree
	inorder(curr->left, prev, ans);

	if (prev != NULL)
		ans = min(abs(curr->stoi(data) - prev->stoi(data)), ans);
	prev = curr;

	// Calling in-order on the right sub-tree
	inorder(curr->right, prev, ans);
}

// Function to return the minimum
// difference between any two nodes
// of the given binary search tree
int minDifference(node* root)
{

    int ans = INT_MAX;
    
	node* prev = NULL;

	//Inorder calling
	inorder(root, prev, ans);

	// Returning the final answer
	return ans;
}

// Driver code
int main()
{
    int n;
    cin >> n;

    node* root = build(n);

	cout << minDifference(root);

	return 0;
}
