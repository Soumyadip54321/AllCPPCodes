#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


/*function overloading*/
class ApnaCollege{
    public:
    void fun(){
        cout<<"I am a function with no arguments"<<endl;
    }
    void fun(int x){
        cout<<"I am a function with int arguments"<<endl;
    }
    void fun(double x){
        cout<<"I am a function with double arguments"<<endl;
    }
};

/*operator overloading*/
class complex{
    int real,imaginary;
    public:

    complex(int r,int i){
        real=r;
        imaginary=i;
    }

    complex operator + (complex const &obj){
        complex result(0,0);
        result.imaginary=imaginary+obj.imaginary;
        result.real=real+obj.real;
        return result;
    }

    void display(){
        cout<<real<<" + i"<<imaginary<<endl;
    }
};

/*runtime polymorphism*/
class base{
    public:
    virtual void print(){
        cout<<"This is the base class's print function"<<endl;
    }
    virtual void display(){
        cout<<"This is the base class's display function"<<endl;
    }
};

class derived: public base{
    public:
    void print(){
        cout<<"This is the derived class's print function"<<endl;
    }
    void display(){
        cout<<"This is the derived class's display function"<<endl;
    }
};


int main(){
    // ApnaCollege obj;
    // obj.fun();
    // obj.fun(5);
    // obj.fun(6.1);
    // complex c1(32,6),c2(5,9);
    // complex c3=c1+c2;
    // c3.display();

    base *baseptr;
    derived d;
    baseptr=&d;

    baseptr->display();
    baseptr->print();

    return 0;
}