class MinStack{
    stack<long long> s;
    long long mini;

    public:

        // Constructor
        MinStack(){
            //empty if there is anything in stack
            while(!s.empty()) s.pop();
            mini = INT_MAX;
        }

        void push(int value){
            long long val = value;

            if(s.empty()){
                mini = val;
                s.push(val);
            }
            else{
                if(val<mini){
                    //push the modified min
                    s.push(2*val - mini);
                    mini = val;
                }
                else{
                    s.push(val);
                }
            }
        }

        void pop(){
            if(!s.empty()){
                return;
            }

            //get the top
            long long element = s.top();
            s.pop();

            if(element<mini){
                //pop the original min
                mini = 2*mini - element;
            }
        }

        int top(){
            if(s.empty()) return -1;

            long long element = s.top();

            if(element< mini) return mini;

            return element;
        }

        int getMin(){
            return mini;
        }
};