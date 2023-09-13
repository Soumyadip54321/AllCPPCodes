#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    /*
    idea:
    1. we use one stack to so long we insert elements
    2. At the time of removing we put all elements into the other stack such that for any 2 elements one inserted earlier
    lies at the top
    3. we then pop element
    4. we perform pop operations as needed following which we reinsert elements in the initial stack
    */
    
    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X){
        stk1.push(X);
        return true;
    }

    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){

        if(not(stk1.empty())){
            while (not(stk1.empty()))
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            int topentry=stk2.top();
            stk2.pop();

            //now we re-fill stk1
            while (not(stk2.empty()))
            {
                stk1.push(stk2.top());
                stk2.pop();
            }

            //we return the element dequeued
            return topentry;
        }
        return -1;
    }
};


int main(){
    Queue q;
    cout<<q.enqueue(11)<<endl;
    cout<<q.enqueue(51)<<endl;
    cout<<q.enqueue(26)<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.enqueue(6)<<endl;
   //cout<<q.enqueue(6)<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}