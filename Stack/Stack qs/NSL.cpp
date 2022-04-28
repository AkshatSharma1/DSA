#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> findNSL(vector<int> arr){

    //make a vector and a stack
    vector<int> v;
    stack<int> s;

    //in this we see that we need our j loop to work from 0 to <=i as we need nearest element to a[i] on top of stack

    //traverse arr in L ->R
    for(int i=0;i<arr.size();i++){

        //Conditions

        //1.if stack size is 0
        if(s.size()==0){
            v.push_back(-1);
        }

        //2. if top of stack is greater than current ith element
        else if(s.size()>0 && s.top() < arr[i]){
            v.push_back(s.top());
        }

        //3. if arr[i] >= top
        else if(s.size()>0 && arr[i]<=s.top()){

            //pop till stack is not epty and top is not smaller
            while(s.size()>0 && arr[i]<=s.top()){
                s.pop();
            }

            //Now if stack becomes empty then pushback -1 or
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            //or push_back top
            else{
                v.push_back(s.top());
            }

        }
        //when all checks are done push the arr[i] in stack to make it look like right array
        s.push(arr[i]);
    }

    //Note: no need to reverse the o/p arr as we traversed in same direction of our i loop
    return v;

}

int main(){
    vector<int> arr = {1,3,2,4};
    vector<int> res;

    //nearest smaller element
    res = findNSL(arr);

    for(auto i: res){
        cout<<i<<" ";
    }

    return 0;
}