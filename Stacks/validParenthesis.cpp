#include<iostream>
#include<string>
#include<stack>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
  
//         if(s.length() == 0)
//         {
//             return true;
//         }
//         if(s.length()==1)
//         {
//             return false;
//         }
//         stack<char> stk;
//         for(int i=0;i<s.length();i++)
//         {
//             char ch = s[i];
//             if(ch == '(' or ch == '{' or ch == '[')
//             {
//                 stk.push(ch);
//             }
//             else if(ch == ')' or ch == '}' or ch == ']')
//             {
//                 if(!stk.empty())
//                 {
//                     switch(ch)
//                     {
//                         case ')':
//                             if(stk.top()=='(')
//                             {
//                                 stk.pop();
//                             }
//                             else
//                             {
//                                 stk.push(ch);
//                             }
//                             break;
                            
//                             case '}':
//                             if(stk.top()=='(')
//                             {
//                                 stk.pop();
//                             }
//                             else
//                             {
//                                 stk.push(ch);
//                             }
//                             break;
                            
//                             case ']':
//                             if(stk.top()=='(')
//                             {
//                                 stk.pop();
//                             }
//                             else
//                             {
//                                 stk.push(ch);
//                             }
//                             break;
//                     }
//                 }
//             }
                
//         }
//         return stk.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else
            {
                if((stk.top()=='('&&s[i]==')')||(stk.top()=='['&&s[i]==']')||(stk.top()=='{'&&s[i]=='}'))
                {
                    stk.pop();
                }
                else{stk.push(s[i]);}
            }
        }
        if(stk.empty())
        {
            return true;
        }
        
        return false;
    }
};

int main()
{
    Solution obj;

    string s = "(){}[}";
    if(obj.isValid(s))
    {
        cout<<"Valid"<<endl;
    } 
    else
    {
        cout<<"Not Valid";
    }

    return 0;
}