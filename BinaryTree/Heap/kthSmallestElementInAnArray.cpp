// using stl
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<int> a = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 3;
 
    nth_element(a.begin(), a.begin() + k - 1, a.end());
 
    cout << "k'th smallest array element is " << a[k - 1];
 
    return 0;
}

//using min heap
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
 
// // Function to find the k'th smallest element in an
// // array using min-heap
// int findKthSmallest(vector<int> const &vec, int k)
// {
//     // create an empty min-heap and initialize it with all elements
//     // `use std::greater` as the comparison function for min-heap
//     priority_queue<int, vector<int>, greater<>> pq(vec.begin(), vec.end());
 
//     // pop from min-heap exactly `k-1` times
//     while (--k) {
//         pq.pop();
//     }
 
//     // return the root of min-heap
//     return pq.top();
// }
 
// int main()
// {
//     vector<int> input = { 7, 4, 6, 3, 9, 1 };
//     const size_t k = 3;
 
//     cout << "k'th smallest array element is " <<
//             findKthSmallest(input, k);
 
//     return 0;
// }

//using max heap 
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
 
// // Function to find the k'th smallest element in an array using max-heap
// int findKthSmallest(vector<int> const &v, int k)
// {
//     // create a max-heap using `std::priority_queue` and
//     // insert the first `k` array elements into the heap
//     priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);
 
//     // do for remaining array elements
//     for (int i = k; i < v.size(); i++)
//     {
//         // if the current element is less than the root of the heap
//         if (v[i] < pq.top())
//         {
//             // replace root with the current element
//             pq.pop();
//             pq.push(v[i]);
//         }
//     }
 
//     // return the root of max-heap
//     return pq.top();
// }
 
int main()
{
    vector<int> input = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 3;
 
    cout << "k'th smallest array element is " << findKthSmallest(input, k);
 
    return 0;
}