

#include <stdio.h>
// using namespace std;

void pattern(int n)
{
    int i, j, k , l,m;
    //right side
	for (i = 0; i <= n-1; i++)
	{
		for (k = 65;  k<= 71-i; k++)
		{
			printf("%c",k);
		}
		// cout << endl;
        for(int j=1;j<=2*i;j++){
            printf(" ");
        }

        for(int l=71-i;l>=65;l--){
            if(l!=71){
                printf("%c",l);
                printf("\n");
            }
        }
        printf(" ");
	}
}
int main()
{
    pattern(7);
	return 0;
}

