#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int leastInterval(int N, int K, vector<char> &tasks);

int main(){
    vector<char> tasks={'A', 'A', 'A', 'B', 'B', 'B'};
    cout<<leastInterval(5,2,tasks);
    return 0;
}
int leastInterval(int N, int K, vector<char> &tasks){
    /*
    idea:
    1. we put pointers at every new task in the Queue
    2. we maintain a variable that keeps track of the number of task done since the first task
    3. if variable value == K(cooldown) we perform the first task
    4. At every pt a task is undertaken we erase it from the vector
    5. we do this until queue is empty
    */

   
}