#include<bits/stdc++.h>
using namespace std;

// int helper(int x,int y)
// {
//     int count = 0;
//     //Base case
//     if(x)
//     {
//         return 0;
//     }

//     return min(helper(x + 2, y), helper(x - 1, y));

// }
int helper(int x,int y)
{
    int count = 0;
    while(x != y)
    {
        if(x<y)
        {
            x += 2;
            count++;
        }
        else if(x>y)
        {
            x -= 1;
            count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        cin >> x >> y;

        cout<< helper(x, y);
        cout << endl;
    }
    return 0;
}