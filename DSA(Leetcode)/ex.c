#include<stdio.h>
#include<math.h>
int main()
{
  float a=1,b=2,c=3,d=4,a1,b1,c1,s;
  s=(c-d)/(a-b);
  a1=d-c;
  b1=b-a;
  c1=((b1*c)-(a1*a));
  printf("Slope = %f",s);    
  printf("\nEquation of Straight Line  = %f  x + %f  y = %f",-a1,b1,c1);
  return 0;
}