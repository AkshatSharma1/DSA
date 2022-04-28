#include<iostream>
#include<stack>

using namespace std;

class node{
    public:
        int data; 
        node* left; 
        node* right; 

        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertBST(node*root,int value)
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

node* build()
{
    int d;
    cin >> d;

    node*root = NULL;
    while(d!=-1){
        root = insertBST(root,d);
        cin>>d;
    }

    return root;
}

void zigzag(node*root)
{
    if(root == NULL)
    {
        return;
    }

    //keep two stacks: currLevel and nextLevel
    stack<node*> currLevel;
    stack<node*> nextLevel;

    //bool var for checking the direction of the traverse
    bool leftToRight = true;

    currLevel.push(root);
    while(!currLevel.empty())
    {
        node* temp = currLevel.top();//answer var
        currLevel.pop();

        if(temp)
        {
            cout<<temp->data<<" ";

            //pushing left and right child of temp
            if(leftToRight)
            {
                //if leftToRight is true then push left child first then right child
                if(temp->left)//not equal to null
                {
                    nextLevel.push(temp->left);
                }
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }

            //If leftToRight is false then push right child first then child left child
            else//(!leftToRight)
            {
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if(temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        //if a level is completed then
        if(currLevel.empty())
        {
            leftToRight = !leftToRight; //change true to false and vice versa
            swap(currLevel,nextLevel);  // swap both stacks
        }
    }
}

int main()
{
    node*root = build();

    zigzag(root);

    return 0;
}
// 12 9 15 5 10 -1
// 12 15 9 5 10 (o/p)