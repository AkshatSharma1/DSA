#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
    stack<int> stk;
    for(int i=0;i<tokens.size();i++)
    {
        if(tokens[i]!="+" or tokens[i]!="-" or tokens[i]!="*" or tokens[i]!="/" or tokens[i]!="^")
        {
            stk.push(atoi(tokens[i].c_str()));
        }
        else
        {
            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();
            char a=tokens[i][0];
            
            switch(a)
            {
                case '+': stk.push(op1 + op2); 
                break;

                case '-': stk.push(op1 - op2);
                break;

                case '*': stk.push(op1 * op2);
                break;

                case '/': stk.push(op1 / op2);
                break;

                case '^': stk.push(pow(op1,op2));
                break;
            }
        }

    }
    
        return stk.top();
    }
};


int main()
{
    Solution obj;
    vector<string> s;
    
    s.push_back("4");
    s.push_back("13");
    s.push_back("5");
    s.push_back("/");
    s.push_back("+");

    obj.evalRPN(s);


return 0;
}

// class Solution {
// public:
//     int operation(int op1,int op2,string op){
//         if(op=="/"){
//             return op2/op1;
//         }else if(op=="*"){
//             return op1*op2;
//         }else if(op=="-"){
//             return op2-op1;
//         }else if(op=="+")
//         {
//             return op1+op2;
//         }
//         else
//         {
//             return pow(op1,op2);
//         }
//     }
    
//     int evalRPN(vector<string>& s) {
        
//            stack<int> stk;
//     for(int i=0;i<=s.size()-1;i++)
//     {
        
//         string token = s[i];
//         if(token=="+" or token=="-" or token=="*" or token=="/" or token=="^")
//         {
//             if(!stk.empty())
//             {
//                 int a = stk.top(); stk.pop();
//                 int b = stk.top(); stk.pop();
//                 int answer = operation(a,b,token);
//                 stk.push(answer);
//             }
            //}
//         else
//         {
//                 stk.push(stoi(token));
//         }
//         
  
//     }
    
//         return stk.top();
//     }
// };
