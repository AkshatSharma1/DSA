#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    queue<char> q;
    int freq[30] = {0};

    //given that take a running stream of characters until a . is there
    char ch;
    cin>>ch;

    while(ch!='.')
    {
        //Logic
        //insert in the queue and also take care of the frq table
        q.push(ch);
        freq[ch - 'a']++;

        while(!q.empty())
        {
            int idx = q.front() - 'a';
            if(freq[idx]>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<endl;
                break;
            } 
        }

        if(q.empty())
        {
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }


    return 0;
}