#include<iostream>
#include<queue>
#include<cmath>
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

int height(node*root) 
{
    if(root == NULL) return 0;

    int ls = height(root->left); //left subtree height
    int rs = height(root->right); //right subtree height

    return max(ls,rs)+1;
}

//Diameter of tree(O(n2))
//2 cases: i) when diameter passes through root which simply is left height + right ht + 1
// ii) when donot pass through root
int diameter(node* root){

    //base case
    if(root==NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currDia = leftHeight + rightHeight + 1;

    //rec call to find diamter
    return max(currDia, max(diameter(root->left), diameter(root->right)));
}

//Optimised diameter(o(n))
int diameterOpt(node* root, int *height){
    if(root==NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;

    //pass pointer as curr height
    int lDia = diameterOpt(root->left, &lh);
    int rDia = diameterOpt(root->right, &rh);

    int currDia = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDia, max(lDia, rDia));
}

//Replace each node by sum(each node data + left subtree nodes data + right subtree node data)
void replaceBySum(node* root){

    //base case: when leaf node no need to change data
    if(root==NULL){
        return;
    }

    //left tree sum
    replaceBySum(root->left); //curr root->left
    //right tree sum
    replaceBySum(root->right);

    //now if curr roots left is not null
    if(root->left!=NULL){
        root->data += root->left->data;
    }

    if(root->right!=NULL){
        root->data += root->right->data;
    }
}

//check if tree is height balanced or not
//it is O(n2) as it calculates heoght at each root for left and right sub tree
bool checkBalancedHeight(node* root){

    // base case
    if(root==NULL) return true;
    //check if left s.t is balanced or not and same for right s.t
    if(!checkBalancedHeight(root->left) or !checkBalancedHeight(root->right)){
        return false;
    }

    //calc height for checking each curr root
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    //check if mod of left - right ht. <=1
    if(abs(lHeight - rHeight)<=1){
        return true;
    }
    else{
        return false;
    }
}

//check height balanced optimised
bool checkBalancedHeight(node* root, int *height){

    // base case
    if(root==NULL){
        *height = 0;
        return true;
    }

    int lh = 0, rh = 0;

    //check if left s.t is balanced or not and same for right s.t
    if(!checkBalancedHeight(root->left, &lh) or !checkBalancedHeight(root->right, &rh)){
        return false;
    }

    *height = max(lh, rh) + 1;

    //check if mod of left - right ht. <=1
    if(abs(lh - rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

//M-3: balanced height
int dfsHeight (node *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
}

bool isBalanced(node *root) {
        return dfsHeight (root) != -1;
}

//Right view of a binary tree
void rightView(node* root){

    if(root==NULL) return;

    //traverse level order and store the rightmost node in the array
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        //now for each level we have n nodes in the queue. thus put/ cout the nth node of each level
        int n = q.size();
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();

            if(i==n-1){
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

//Left view of a binary tree
void leftView(node* root){

    if(root==NULL) return;

    //traverse level order and store the rightmost node in the array
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        //now for each level we have n nodes in the queue. thus put/ cout the nth node of each level
        int n = q.size();
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();

            //if first element of queue
            if(i==0){
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}


//count nodes
int countNodes(node*root){
    if(root==NULL) return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

//sum of all nodes
int sumNodes(node* root){
    if(root==NULL) return 0;

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

void KthlevelOrder(node* root,int k)
{
    if(root == NULL) return;

    if(k==1)//end level 
    {
        cout<<root->data<<" ";
        return;
    }

    KthlevelOrder(root->left,k-1);
    KthlevelOrder(root->right,k-1);
}

void printLevelOrder(node* root){
    if(root==NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    //now we pop out every node from the queue.
    //If null is popped out it means a level is done then we will again push it back
    while(!q.empty()){
        node* node = q.front();
        q.pop();

        if(node==NULL){
            //print the values
            cout<<node->data<<" ";
            //now pushv the left side of curr root
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        else if(!q.empty()){
            q.push(NULL);        }
    }

}

void printAllLevels(node* root)
{
    int ht = height(root);

    for(int i=1;i<=ht;i++)
    {
        KthlevelOrder(root,i);
        cout<<endl;
    }

    return;
}

//Level Order(BFS Queue Method)
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
        }

    }
    return;
}

int sumAtK(node*root,int k)
{
    if(root==NULL) return -1;
    queue<node*> q; //int should not be used bcoz we want to know its children and by taking only data like int we cant know what are its children. So we will use node or node* instead
    //push root first 
    q.push(root);
    q.push(NULL);

    int level = 1;//track level here starts from 1. if level=0 then starts from 0.
    int sum = 0;

    while(!q.empty())
    {
        //take the data into consideration not node, so here q.front will give node 
        node* frontNode = q.front();
        q.pop();

        if(frontNode!=NULL)
        {
            if(level == k)
            {
                sum+=frontNode->data;
            }

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
            level++; //shows a level is traversed
        }

    }
    return sum;
}

int main()
{
    node* root = buildTree();
    // cout<<"Preorder traversal is: ";
    // preorderPrint(root);
    // cout<<endl;

    // cout<<"Inorder traversal is: ";
    // InorderPrint(root);
    // cout<<endl;

    // cout<<"Postorder traversal is: ";
    // postorderPrint(root);
    // cout<<endl;

    //Calc height
    // cout<<height(root);

    // KthlevelOrder(root,4);
    // printAllLevels(root);

    cout<<endl;
    cout<<"Level Order(BFS) traversal is:"<<" ";
    bfsTraversal(root);

    cout<<endl;
    cout<<"Sum at praticulat level is: "<<" ";
    cout<<sumAtK(root,3);

    cout<<endl;
    cout<<"Node count: "<<countNodes(root);

    cout<<endl;
    cout<<"Nodes sum: "<<sumNodes(root);

    cout<<endl;
    cout<<"Diameter: "<<diameter(root);

    cout<<endl;
    int height = 0;
    cout<<"Diameter optimised: "<<diameterOpt(root, &height);

    cout<<endl;
    replaceBySum(root);

    cout<<endl;
    cout<<"Level Order(BFS) traversal is:"<<" ";
    bfsTraversal(root);

    cout<<endl;
    cout<<"Right View is: "<<" ";
    rightView(root);

    cout<<endl;
    cout<<"Left View is: "<<" ";
    leftView(root);
    return 0;
}
//sample input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
/*
             8
            /  \
          10    3 
          / \    \
         1   6    14 
            / \   /  
           9   7 13

*/          