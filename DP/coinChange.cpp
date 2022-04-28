#include<iostream>
using namespace std;

//Recursive

// int maxWays(int coin[], int amount, int n){
//     //Base Condition
//     if(amount == 0)
//         return 1;
//     else if(n == 0 && amount != 0)
//         return 0;
//     //Choices
//     else if(coin[n-1] <= amount)
//         return (maxWays(coin, amount-coin[n-1], n) + maxWays(coin, amount, n-1));
//     else
//         return maxWays(coin, amount, n-1);
// }


//DP

int maxNoOfWays(int coin[], int amount, int n)
{

    int t[n+1][amount+1];

    //Initialization
    for(int i =0; i < n+1; i++){
        for(int j = 0; j < amount+1; j++){
            if(j==0)
                t[i][j] = 1;
            else if(i==0 && j!=0)
                t[i][j] = 0;
        }
    }

    //across the rows
    for(int i = 1; i < n+1; i++){
        
        //across the columns
        for(int j = 1; j < amount+1; j++){
        
            // we can include or exclude the coin
            if(coin[i-1] <= j) 
                
                //if value of coin is less than or equal to the amount the we'll 
                //have two choices : Include the coin or exclude the coin
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j]; 
            else
                // Excluding the coin
                t[i][j] = t[i-1][j]; 
        }
    }

    return t[n][amount];
}

int main(){

    int coin[] = {1,2,3};
    int amount = 5;
    int n = sizeof(coin)/sizeof(coin[0]);

    cout<<"Max number of ways are: "<<maxNoOfWays(coin, amount, n);
    return 0;
}