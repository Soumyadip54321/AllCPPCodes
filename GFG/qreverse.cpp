#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
queue<int> rev(queue<int> q);

int main(){
    queue<int> q,revq;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    revq=rev(q);

    return 0;
}
queue<int> rev(queue<int> q){
    stack<int> s;

    while (not(q.empty()))
    {
        s.push(q.front());
        q.pop();
    }

    while (not(s.empty()))
    {
        q.push(s.top());
        s.pop();
    }

    //display
    // while (not(q.empty()))
    // {
    //     cout<<q.front()<<",";
    //     q.pop();
    // }
    // cout<<endl;
    return q;
}