/* SPOJ/DEFK

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
This position has a penalty of 12.
Help Theodore write a program that calculates the penalty of the given position.

Input
The first line of the input file contains the number of test cases.

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int w,h,n;
    cin>>t;
    int x[40010],y[40010];

    while(t--)
    {
        cin>>w>>h>>n;
        for(int i=0;i<n;i++)
        {
            //store coordinates of ith tower 
            cin>>x[i]>>y[i];
        }

        //now sort the coordinates
        sort(x,x+n);
        sort(y,y+n);

        //find delta x and delta y (x2-x1) & (y2-y1)
        int delta_x = x[0] - 1;
        int delta_y = y[0] - 1; //initial
        for(int i=1;i<n;i++)
        {
            delta_x  = max(delta_x,x[i] - x[i-1] -1);
            delta_y = max(delta_y,y[i] - y[i-1] - 1);
        }

        //corner case(grid is ending)
        delta_x = max(delta_x,w-x[n-1]);
        delta_y = max(delta_y,h-y[n-1]);

        //now area
        cout<<delta_x*delta_y<<endl;
    }
    return 0;
}