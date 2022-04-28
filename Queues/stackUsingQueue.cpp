/*Two methods:
            a) Push method is costly
            b) Pop method is expensive
*/

//Method 1: Push method is expensive
/* i)take two queues q1 and q2. 
   ii)Now push the element in q2 and all the elements present in q1 are pushed to q2. 
   iii)Then q2 and q1 are swapped
   iv) For popping, simply pop from q1*/

#include<iostream>
#include<queue>
using namespace std;

// class Stack{
//     int n;//size
//     queue<int> q1;
//     queue<int> q2;

//     public:
//         Stack()
//         {
//             n=0;
//         }

//         void push(int value)
//         {
//             q2.push(value);
//             n++;
//             //all elements in q1 are pushed to q2
//             while(!q1.empty())
//             {
//                 q2.push(q1.front());
//                 q1.pop();
//             }

//             //To reverse the queues
//             queue<int> temp = q1;
//             q1 = q2;
//             q2 = temp;
//         }

//         void pop(){
//             q1.pop();
//             n--;
//         }

//         int top(){
//             return q1.front();
//         }

//         int getSize(){
//             return n;
//         }
// };

/*Methos 2: making pop function expensive
i)Insert in q1 
ii)Pop all elements except first one from q1 and push it to q2
iii) Pop the remaining from q1 and swap q2 and q1 */
class Stack{
    int n;//size
    queue<int> q1;
    queue<int> q2;

    public:
        Stack()
        {
            n=0;
        }

        void push(int value)
        {
            q1.push(value);
            n++;
        }

        void pop(){
            if(q1.empty())
            {
                return;
            }

            while(q1.getSize()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            q1.pop();
            n--;

            //Swap 
            queue<int> temp = q1;
            q1=q2;
            q2 = temp;

        }

        int top(){
            if(q1.empty())
            {
                return -1;
            }

            while(q1.getSize()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int ele = q1.front();
            q2.push(ele);

            queue<int> temp = q1;
            q1=q2;
            q2 = temp;

            return ele;

        }

        int getSize(){
            return n;
        }
};

int main(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

 
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

    return 0;
}