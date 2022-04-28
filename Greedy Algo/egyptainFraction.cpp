/*
    Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians. 
Following are few examples: 
 

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction, then recur for the remaining part. For example, consider 6/14, we first find ceiling of 14/6, i.e., 3. So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42. 
Below is implementation of above idea.

*/
#include<iostream>
using namespace std;

void printFraction(int nr,int dr)
{
    //If either num=0 or den=0, print
    if(nr==0 or dr==0)
    {
        return;
    }

    //now,if numerator divided denominator e.g. 3/6
    if(dr%nr==0)
    {
        cout<<"1/"<<dr/nr;
        return;
    }

    //now,if denominator divided numerator e.g. 6/3
    if(nr%dr==0)
    {
        cout<<nr/dr;
        return;
    }

    //Now, if numerator > denominator and not complete;y divide
    if(nr > dr)
    {
        cout<<nr/dr<<" + ";
        printFraction(nr%dr,dr);
        return;
    }

    //now when dr>nr e.g. 6/14
    //find ceiling of dr/nr i.e. 16/4 + 1 
    int ceiling = dr/nr + 1;
    cout<<"1/"<<ceiling<<" + ";
    //now recursive for nr/dr - 1/ceiling
    printFraction(nr*ceiling-dr,dr-ceiling);
}

int main()
{
        int nr = 6, dr = 14;
    cout << "Egyptian Fraction Representation of "
         << nr << "/" << dr << " is\n ";
    printFraction(nr, dr);
    return 0;
}