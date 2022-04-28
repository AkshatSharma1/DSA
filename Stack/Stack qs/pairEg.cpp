#include<iostream>
#include"pairClass.cpp"
using namespace std;

int main(){

    //creating a triplet
    Pair<Pair<int,int>, int> p2;

    p2.setY(10);

    //to set data in X we have to give it a pair value as it is defn as pair
    Pair<int, int> p3;
    p3.setX(5);
    p3.setY(7);

    p2.setX(p3);

    //get p2's Y and X
    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;

    return 0;
}