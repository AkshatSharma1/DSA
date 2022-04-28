#include <iostream>
using namespace std;

int main() 
{
 int a [10][10];
 for (int i=0; i<=10; i++)
 {
   for(int j=0; j<=10; j++)
   {
     if ((i+j) % 2==0)
     {
       a[i][j] = 2*(i+j);
     }
     else
     {
       a[i][j] = 3*(i+j);
     }
   }
 }
 
 for(int i=0;i<=10;i++)
 {
     for(int j=0;j<=10;j++)
     {
         cout<<a[i][j]<<" ";
     }
 }
}