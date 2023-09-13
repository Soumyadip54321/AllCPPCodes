#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    int bot2;                       //holds the pointer to the base of stack2
    int firstpush2=0;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = -1;
        bot2=-1;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top1+1!=bot2){
            top1+=1;
            arr[top1]=x;
        }
        else{
            //here we shift all elements in stack2 starting from top upwards by 1 to accomodate a single insertion in stack1
            int p=top2;
            while (p>=bot2)
            {
                arr[p+1]=arr[p];
                p--;
            }
            bot2+=1;            //bottom shifts up by 1 place & so does top2;
            top2+=1;
            
            top1+=1;
            arr[top1]=x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(firstpush2==0){
            top2=top1+1;
            bot2=top2;
            firstpush2++;
        }
        else
            top2+=1;
        
        arr[top2]=x;
        //cout<<firstpush2<<" "<<bot2<<" "<<top2<<endl;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1<0)
            return top1;

        int num=arr[top1];
        top1-=1;

        if(top1<0)
            top1=-1;
        return num;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2<0){
            return top2;
        }
        
        int num=arr[top2];
        top2-=1;

        if(top2<bot2){              //if there exists no further items in stack2 we make it empty.
            top2=-1;
            bot2=-1;
            firstpush2=0;
        }
        return num;
        
    }
};

int main(){
    twoStacks s=twoStacks();
    s.push1(1);
    s.push1(2);
    //s.push1(8);
    s.push2(8);
    s.push2(9);

    // cout<<s.pop1()<<endl;
    // s.push1(3);
    // cout<<s.pop1()<<endl;
    // cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;

    s.push2(11);
    s.push2(21);
    s.push2(55);
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
    return 0;
}