#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
 
// Recursive Method
int binomialCoeffRec(int n, int r)
{
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();

    // Base Cases
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
 
    // Recursive
    return binomialCoeffRec(n - 1, r - 1) + binomialCoeffRec(n - 1, r);
}

// Dynamic Programming Method
int binomialCoeffDynamic(int n, int r)
{
    int C[n + 1][r + 1];
 
    // Bottom Up
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Finding previously stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    return C[n][r];
}
 

int main()
{
    cout << "\nCase 1: When n = 5 and r = 2\n";
    int n = 5, r = 2;
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();
    cout << "\n*************** Recursive way implementation ******************\n";
    cout << "Value of C(" << n << ", " << r << ") is " << binomialCoeffRec(n, r);
    auto t1 = Time::now();
    fsec fs = t1 - t0;
    cout << "\nTime taken to give result: "<< fs.count()<<" seconds" << endl;

    t0 = Time::now();
    cout << "\n\n******************* Dynamic Programming Approach *****************\n";
    cout << "Value of C(" << n << ", " << r << ") is " << binomialCoeffDynamic(n, r);
    t1 = Time::now();
    fs = t1 - t0;
    cout << "\nTime taken to give result: "<< fs.count()<<" seconds" << endl;

    cout << "\n\n-----------------------------------------------------------------------\n";
    cout << "\nCase 2: When n = 5 and r = 5 (i.e. when both values are same)\n";
    t0 = Time::now();
    n = 5, r = 5;
    cout << "\n*************** Recursive way implementation ******************\n";
    cout << "Value of C(" << n << ", " << r << ") is " << binomialCoeffRec(n, r);
    t1 = Time::now();
    fs = t1 - t0;
    cout << "\nTime taken to give result: "<< fs.count()<<" seconds" << endl;

    t0 = Time::now();
    cout << "\n\n******************* Dynamic Programming Approach *****************\n";
    cout << "Value of C(" << n << ", " << r << ") is " << binomialCoeffDynamic(n, r);
    t1 = Time::now();
    fs = t1 - t0;
    cout << "\nTime taken to give result: "<< fs.count()<<" seconds" << endl;

    return 0;
}