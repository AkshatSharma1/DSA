#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b) {
    return a.first > b.first; //fuel station nearer to town will be bigger one
}

int main()
{
    int n,t,x,d,f,D,F,prev = 0;
    int flag = 0;
    int ans=0;
    cin>>t;

    while(t--)
    {
        //vector to store fuel station and its distace from bus
        vector<pair<int,int> > v;
        //priority queue for storing fuel capacity
        priority_queue<int> pq;

        cin>>n; //take fuel station stops

        for(int i=0;i<n;i++)
        {
            cin>>d>>f; 
            v.push_back(make_pair(d,f));

        }

        //now sort according to fuel capacity high
        sort(v.begin(),v.end(),compare);

        //initial distance and fuel in bus
        cin>>D>>F;

        //Update distance of fuel station from bus
        for(int i=0;i<n;i++)
        {
            v[i].first = D - v[i].first; //subtract initial from travelled station
        }

        //prev denotes the previous city we visited
        prev = 0;
        x = 0;//current city

        while(x<n)//traverse whole
        {
            //if enough fuel to travel to next city then
            if(F>=(v[x].first - prev))
            {
                F = F-(v[x].first-prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                //if stations already visited then
                if(pq.empty())
                {
                    flag = 1;
                    break;
                }
                
                //refuel truck with higher capacity
                F+=pq.top();
                pq.pop();
                ans+=1;
                continue;
                
            }
            x++;

        }
        //now reach town from last fuel stations
        //here no more fuel stations available
        if(flag==1)
        {
            cout<<"-1"<<endl;
        }
        //else
        D = D - v[n-1].first;

        //if enough fuel present
        if(F>=D)
        {
            cout<<ans<<endl;
            continue;
        }
        //otherwise
        while(F<D)
        {
            if(pq.empty())
            {
                flag = 1;
                break;
            }
            F+=pq.top();
            pq.pop();
            ans+=1;
        }
        //oherwise not able to reach
        if(flag==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        //else
        cout<<ans<<endl;

    }

    return 0;
}