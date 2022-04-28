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

//Preorder traversal and print tree
void preorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//Inorder traversal and print tree
void InorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

//Postorder traversal and print tree
void postorderPrint(node* root) 
{
    if(root == NULL) 
    {return;}

    //else print
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

//Height of a tree
int height(node*root) 
{
    if(root == NULL) return 0;

    int ls = height(root->left); //left subtree height
    int rs = height(root->right); //right subtree height

    return max(ls,rs)+1;
}

//Diameter of a tree
// int diameter(node* root)
// {
//     if(root == NULL){
//         return 0;
//     }

//     int h1 = height(root->left);
//     int h2 = height(root->right);

//     //case 1: If diameter passes through root
//     int case1 = h1 + h2;

//     //If diameter donot passes through root and lies in the left subtree
//     int case2 = diameter(root->left);

//     //If diameter donot passes through root and lies in the right subtree
//     int case3 = diameter(root->right);

//     int finalDiameter = max(case1,max(case2,case3));

//     return finalDiameter;

// }

//diameter of a tree( Optimized Method)
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node*root) {

    Pair p;
    if(root == NULL)
    {
        p.diameter=0;
        p.height=0;
        return p;
    }

    //else
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height + right.height,max(left.diameter,right.diameter));

    return p;
}

int main()
{
    node* root = buildTree();

    cout<<endl;
    // cout<<"Diameter of the tree is: "<<" "<<diameter(root);

    Pair ans = fastDiameter(root);
    cout<<"Height of the tree is: "<<" "<<ans.height<<endl;
    cout<<"Diameter of the tree is: "<<" "<<ans.diameter<<endl;

    return 0;
}