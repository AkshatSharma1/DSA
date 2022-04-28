#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int testCases;
    int n;//no. of tasks 
    int s,e;

    cin>>testCases;

    vector<pair<int,int> > v;//(starting,ending) time

    while(testCases--){

        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }

        //Activities sorting according to their end time
        sort(v.begin(),v.end(),compare);

        //starting picking Activities
        //pick first activity manually
        int res = 1; //result = 1 means first activity is done/taken
        int finish = v[0].second;

        //iterate over rest Activities
        for(int i=1;i<n;i++)
        {
            if(v[i].first >= finish)
            {
                finish = v[i].second;
                res++;
            }
        }

        cout<<endl;
        cout<<res<<endl;
        v.clear();//so that we can take next input
    }
    

    return 0;
}