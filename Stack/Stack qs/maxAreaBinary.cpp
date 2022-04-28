#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

int getMaxArea(vector<int> arr, int n)
{
    vector<int> left, right;
    stack<pair<int, int>> s1, s2;
    int pseudo_index = -1;
    int pseudo_index1 = n;
    for (int i = 0; i < n; i++)
    {
        if (s1.size() == 0)
        {
            left.push_back(pseudo_index);
        }
        else if (s1.size() > 0 && s1.top().first < arr[i])
        {
            left.push_back(s1.top().second);
        }
        else if (s1.size() > 0 && s1.top().first >= arr[i])
        {
            while (s1.size() > 0 && s1.top().first >= arr[i])
            {
                s1.pop();
            }
            if (s1.size() == 0)
            {
                left.push_back(pseudo_index);
            }
            else
            {
                left.push_back(s1.top().second);
            }
        }
        s1.push({arr[i], i});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
        {
            right.push_back(pseudo_index1);
        }
        else if (s2.size() > 0 && s2.top().first < arr[i])
        {
            right.push_back(s2.top().second);
        }
        else if (s2.size() > 0 && s2.top().first >= arr[i])
        {
            while (s2.size() > 0 && s2.top().first >= arr[i])
            {
                s2.pop();
            }
            if (s2.size() == 0)
            {
                right.push_back(pseudo_index1);
            }
            else
            {
                right.push_back(s2.top().second);
            }
        }
        s2.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m = max(m, (right[i] - left[i] - 1) * arr[i]); // taking max after finding area
    }
    return m;
}

// Using only one stack
int getMaxAreaHist(vector<int> heights, int n)
{
    stack<int> s;

    int nsl[n], nsr[n];

    // finding nsl
    for (int i = 0; i < n; i++)
    {
        // checking if in stack is there any bigger value than current i on top of stack
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        // now if it is first element of arr(means no left element to this element so push 0 in left arr) then tehre will be no element in stack
        // i.e stack is empty and also when other than first element cond tehres no left smaller push 0
        if (s.empty())
            nsl[i] = 0;

        // now when stack is not empty and currenet ith val is greater than the s.top means smaller left is found then push s.top + 1 in left smaller arr
        // +1 is done bcoz s.top() contains the index of previous to ith element
        else
            nsl[i] = s.top() + 1;

        // push
        s.push(i);
    }

    // empty the stack for nsr calculations

    while (!s.empty())
        s.pop();

    // nsr calcs
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() > 0 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if (s.size() == 0)
            nsr[i] = n - 1;
        else
            nsr[i] = s.top() - 1;

        // push
        s.push(i);
    }

    // max area calcs
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (nsr[i] - nsl[i] + 1) * heights[i]);
    }

    return maxArea;
}

// less lines of code
// one itertaion for nsl and nsr
int getMax(vector<int> heights)
{
    stack<int> s;
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        // while stack is not empty adn its top is not greater than curr i and it is also not at the last posi
        while (s.size() > 0 && (heights[s.top()] >= heights[i] || i == n))
        {
            int heightOfBar = heights[s.top()]; //
            s.pop();

            // calc fir nsr and nsl for width
            int width;
            if (s.size() == 0)
                width = i;
            else
                width = i - s.top() - 1;
            maxArea = max(maxArea, width * heightOfBar);
        }
        s.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size(), result = 0;
    vector<int> histogram(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }

        result = max(result, getMax(histogram));
    }
    return result;
}

int main()
{
    // vector<int> heights = {6,2,5,4,5,1,6};
    int n = 4;
    vector<vector<char>> heights( n , vector<char> (n));
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>heights[i][j];
        }
    }
    // vector<vector<char>> heights {
    //     {"1", "0", "1", "0", "0"},
    //     {"1", "0", "1", "1", "1"}, 
    //     {"1", "1", "1", "1", "1"}, 
    //     {"1", "0", "0", "1", "0"}
    // };
    // int n = heights.size();
    int res;

    res = maximalRectangle(heights);
    cout << res;

    return 0;
}