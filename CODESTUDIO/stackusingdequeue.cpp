#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int n=1e5+10;

class Stack
{
    int* ds;
public:
    // Initialize your data structure.
    Stack()
    {
        ds=new int[n];
        if(ds==nullptr)
            exit(-1);
        
        for(int i=0;i<n;i++)
            ds[i]=0;
        
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        for(int i=0;i<n;i++){
            if(ds[i]==0){
                ds[i]=x;
                return true;
            }
        }
        return false;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        // Write your code here.
        int i=n-1;
        while (i>=0)
        {
            if(ds[i]>0){
                int top_item=ds[i];
                ds[i]=0;
                return top_item;
            }
            i--;
        }
        return -1;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        // Write your code here.
        if(ds[0]==0)
            return -1;
        
        int i=n,num;

        do
        {
            i--;
            num=ds[i];
        }while(ds[i]==0);
        
        return num;
    }
    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        // Write your code here.
        if(ds[0]==0)
            return true;
        return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        // Write your code here.
        int i=0,ds_size=0;

        while (ds[i]>0)
        {
            ds_size++;
            i++;
        }
        return ds_size;
    }
};

int main(){
    Stack s=Stack();
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.push(16)<<endl;
    cout<<s.pop()<<endl;
    cout<<s.push(14)<<endl;
    cout<<s.push(10)<<endl;
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.push(37)<<endl;
    return 0;
}