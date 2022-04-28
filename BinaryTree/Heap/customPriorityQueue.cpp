//functional object 
//make a priority queue object of persons and give priority acc to their age

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

//making a basic functional object 
class Fun{
    public:
        void operator()(string s){
            cout << "having fun inside the function "<<s;
        }
};

//person priority queue class
class Person{
    public:
        string name;
        int age;

        Person()
        {

        }

        Person(string n,int a){
            name = n;
            age =a;

        }
};

//compare class 
class Compare{
    public:

        bool operator()(Person a,Person b){
            return a.age < b.age;
        }
};

int main(){

    // Fun f;
    // f("C++");

    int n;
    cin>>n;

    //make a priority queue of persons which compares two persons
    priority_queue<Person,vector<Person>,Compare> pq;

    for(int i=0;i<n;i++){
        string name;
        int age;
        cin>>name>>age;

        Person p1(name,age);
        pq.push(p1);

    }

    //print
    int k = 3;
    for(int i=0;i<k;i++)
    {
        Person p1 = pq.top();
        
        cout<<p1.name<<" and "<<p1.age<<endl;

        pq.pop();
    }



    return 0;

}
