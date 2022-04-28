#include<bits/stdc++.h>
using namespace std;

// void print_map(map<char, int> const &m)
// {
//     for (auto const &pair: m) {
//         cout << "{" << pair.first << ": " << pair.second << "}\n";
//     }
// }

pair<int,int> winner1(char** arr,int x,int y,int n)
{
    int x_needed = 0;
    int sol = 0;
    int minX = 0;
    for(int i = x;i < n;i++)
    {
        map<char,int> freq;
        for(int j = y;j < n;j++)
        {
            freq.insert(make_pair(arr[i][j], freq[arr[i][j]]++));
        }
        auto x_value = freq.find('X');

        
        if(freq.find('O') == freq.end())
        {   
            if(x_value != freq.end())
            {   
                minX = max(n-x_value->second,minX);
                x_needed = n - ((x_value)->second);
            }
            else 
            {
                minX = max(n,minX);
                x_needed = n;
            }

            minX = min(minX, x_needed);
        }
    }

    for(int i = x;i < n;i++)
    {
        map<char,int> freq;
        for(int j = y;j < n;j++)
        {
            freq.insert(make_pair(arr[i][j], freq[arr[i][j]]++));
        }
        auto x_value = freq.find('.');

        
        if(freq.find('O') == freq.end())
        {   if(minX==x_value->second)
                sol++;
        }
    }


    pair<int,int> pairAns = make_pair(minX,sol);
    // cout<<pairAns.first<<" "<<pairAns.second<<endl;
    return pairAns;

}

pair<int,int> winner2(char** arr,int x,int y,int n)
{
    int x_needed = 0;
    int minX = 0;
    int sol = 0;
    for(int i = x;i < n;i++)
    {
        map<char,int> freq;
        for(int j = y;j < n;j++)
        {
            freq.insert(make_pair(arr[j][i], freq[arr[j][i]]++));
        }
        auto x_value = freq.find('X');

        if(freq.find('O') == freq.end())
        {
            
            if(x_value != freq.end())
            {   
                minX = max(n-x_value->second,minX);
                x_needed = n - ((x_value)->second);
            }
            else
            {
                minX = max(n,minX);
                x_needed = n;
            }

            minX = min(minX, x_needed);
        }

    }

    for(int i = x;i < n;i++)
    {
        map<char,int> freq;
        for(int j = y;j < n;j++)
        {
            freq.insert(make_pair(arr[j][i], freq[arr[j][i]]++));
        }
        auto x_value = freq.find('.');

        
        if(freq.find('O') == freq.end())
        {   
           if(minX==x_value->second)
                sol++;
        }
    }


    pair<int,int> pairAns = make_pair(minX,sol);
    // cout<<pairAns.first<<" "<<pairAns.second<<endl;
    return pairAns;

}

pair<int,int> answer1(char** arr,int x,int y,int n)
{
    pair<int,int> case1 = winner1(arr,0,0,n); // row major
    // cout<<case1.first<<" "<<case1.second<<endl;

    pair<int,int> case2 = winner2(arr,0,0,n);//column major
    // cout<<case2.first<<" "<<case2.second<<endl;

    pair<int,int> answer;
    if(case1.first==0 and case2.first==0)
    {
        // string s = "Impossible";
        answer = make_pair(0,0);
        return answer;
    }
    else if(case1.first!=case2.first and (case1.second == 1 and case2.second == 1))
    {
        answer = make_pair(min(case1.first,case2.first),min(case1.second,case2.second));
        return answer;
        // cout<<min(case1.first,case2.first)<<" "<<min(case1.second,case2.second)<<endl;
    }
    else if((case1.first == case2.first) and (case1.second == 1 and case2.second == 1) )
    {
        answer = make_pair(min(case1.first,case2.first),(case1.second + case2.second));
        return answer;
        // cout<<min(case1.first,case2.first)<<" "<<case1.second + case2.second<<endl;
    }
    else if((case1.first == 1 and case2.first ==1) and (case1.second!=case2.second))
    {
        answer = make_pair(min(case1.first,case2.first),max(case1.second,case2.second));
        return answer;
        // cout<<min(case1.first,case2.first)<<" "<<max(case1.second,case2.second)<<endl;
    }
    else
    {
        answer = make_pair(min(case1.first,case2.first),(case1.second + case2.second));
        return answer;
        // cout<<min(case1.first,case2.first)<<" "<<case1.second + case2.second<<endl;
    }

}

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;//size of grid array
        cin>>n;

        char** arr = new char*[n];
        for(int i=0;i<n;i++)//for each row make a row
        {
            arr[i] = new char[n];
        }

        //Take Input
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        auto getAns = answer1(arr,0,0,n);


        // auto result = winner(arr,0,0,n);
        if(getAns.first==0 and getAns.second==0)
        {
            cout<<"Case #"<<k<<": "<<"Impossible"<<endl;
        }
        else
        {
            cout<<"Case #"<<k<<": "<<getAns.first<<" "<<getAns.second<<endl;
        }
        
    }
    return 0;
}