#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target);

int main(){
    vector<char> letters={'c','f','j'};
    cout<<nextGreatestLetter(letters,'j');
    return 0;
}
char nextGreatestLetter(vector<char>& letters, char target){
    /*
    idea:
    1. as seq of chars in letters is increasing we find the ASCII diff of each from target
    2. next we output the one with leats diff
    */
    char nextgreat;
    int mindiff=INT_MAX;
    
    if(letters[letters.size()-1]-target<=0)
        return letters[0];
    
    int i=letters.size()-1;

    while (i>=0 && letters[i]-target>0)
    {   
        if(mindiff>=letters[i]-target){
            mindiff=letters[i]-target;
            nextgreat=letters[i];
        }
        i--;
    }
    return nextgreat;
}