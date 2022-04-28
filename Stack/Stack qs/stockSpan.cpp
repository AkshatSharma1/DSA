// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;

vector<int> stockSpan(vector<int> prices, int n){

    //make a vector and a stack
    vector<int> v;
    stack<pair<int,int>> s;

    //traverse arr in L->R
    for(int i=0;i<n;i++){

        //Conditions

        //1.if stack size is 0
        if(s.size()==0){
            v.push_back(-1);
        }

        //2. if top of stack is greater than current ith element
        else if(s.size()>0 && s.top().first > prices[i]){
            v.push_back(s.top().second);
        }

        //3. if arr[i] >= top
        else if(s.size()>0 && prices[i]>=s.top().first){

            //pop till stack is not epty and top is not smaller
            while(s.size()>0 && prices[i]>=s.top().first){
                s.pop();
            }

            //Now if stack becomes empty then pushback -1 or
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            //or push_back top
            else{
                v.push_back(s.top().second);
            }

        }
        //when all checks are done push the arr[i] in stack to make it look like right array
        s.push({prices[i],i});
    }

    // traverse in v vector and apply formula
    for(int i=0;i<v.size();i++){
        v[i] = i - v[i];
    }
    return v;

}

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};
    int n = prices.size();
    vector<int> res;

    res = stockSpan(prices, n);

    for(auto i: res){
        cout<<i<<" ";
    }

    return 0;
} 