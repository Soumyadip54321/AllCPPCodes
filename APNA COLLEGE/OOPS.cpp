#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class student{
    string name;

    public:
    int age;
    bool gender;

    /*parameterised constructor*/
    student(string s,int years,bool gen){
        name=s;
        age=years;
        gender=gen;
    }

    /*default constructor*/
    student(){
        cout<<"default constructor"<<endl;
    }

    /*copy constructor*/
    student(student &a){
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    /*destructor*/
    ~student(){
        cout<<"Destructor called"<<endl;
    }

    /*setter*/
    void setname(string s){
        name=s;
    }

    /*getter*/
    void getname(){
        cout<<name<<endl;
    }

    void printinfo(){
        cout<<"Name: ";
        cout<<name<<endl;
        cout<<"Age: ";
        cout<<age<<endl;
        cout<<"Gender: ";
        cout<<gender<<endl;
    }

    /*operator overload: used when we want certain operators to behave as we intend to*/
    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender)
            return true;
        return false;
    }
};


int main(){

    /*To form an array*/
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     string s;
    //     cout<<"Name: ";
    //     cin>>s;
    //     arr[i].setname(s);
    //     cout<<"Age: ";
    //     cin>>arr[i].age;
    //     cout<<"Gender: ";
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++)
    //     arr[i].printinfo();

    student a("Soumyadip",32,1);
    student b("urvi",21,0);
    student c=a;
    //a.getname();
    a.printinfo();
    c.printinfo();

    if(b==a)
        cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;


    return 0;
}