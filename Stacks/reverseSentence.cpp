#include<iostream>
#include<stack>
using namespace std;

void reverse_sentence(string s)
{
    stack<string> stk;
    

    for(int i = 0; i < s.length(); i++)
    {
        string word = " ";
        while(s[i]!=' ' and i<s.length())
        {
            word+=s[i];
            i++;
        }
        stk.push(word);

    }

    //For printing
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

}

int main()
{
    string ss= "Hey, man how are you doing?";
    reverse_sentence(ss);
    return 0;
}