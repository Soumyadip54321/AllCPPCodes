#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int arraySign(vector<int>& nums);
int minimumRecolors(string blocks, int k);
int white_checker(string);
int secondsToRemoveOccurrences(string s);       //this removes all occurances of '01' in a binary string in 1sec.
int partition(string,int,int&,string&);
string shiftingLetters(string s, vector<vector<int>>& shifts);
string form_words(string,int,int,int);
string backward_shift(string,int);
string forward_shift(string,int);
int min_operations=100;

vector<string> alphabets={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int main(){
    vector<int> v={-1,1,-1,1,-1};
    string blocks = "WBBWWBBWBWWWBBWBBBBBW",s="00110110111011001000000010111011110100101010100011101111011111011100101000100010111100001011001000000010100100100111111010000000010000111100001111110100011101110110001111101011110000110101111101100110";
    string s1="oeersblikjupeeozwopbpvxpwzbhyjkqmohhsbpwurmalalhrtpimmlheptkniqctepaxxtulkuwoasohkhizmhwkqqxxjdkswpuqomuedsdbdwevmpitofnlurmrbbrbbevjdsahrcypfyynfvxrbtpodjqzmdjylrblzvptstbyefqtuqvphffdamdphgpminpuycq";
    vector<vector<int>> shifts={{0,0,0},{1,1,1}};
    int k=5;
    // cout<<arraySign(v)<<endl;
    // cout<<minimumRecolors(blocks,k)<<endl;
    //cout<<secondsToRemoveOccurrences(s)<<endl;
    cout<<shiftingLetters(s1,shifts)<<endl;
    return 0;
}
int arraySign(vector<int>& nums){
    int num_negative=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
            return 0;
        if(nums[i]<0)
            num_negative++;
    }
    if(num_negative%2==0)
        return 1;
    return -1;
}
int minimumRecolors(string blocks, int k){
    string parted_str="";
    for(int i=0;i<=blocks.length()-k;i++){
        parted_str=blocks.substr(i,k);
        min_operations=min(min_operations,white_checker(parted_str));
    }
    return min_operations;
}
int white_checker(string s){
    int count_whites=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='W')
            count_whites++;
    }
    return count_whites;
}
int secondsToRemoveOccurrences(string s){
    int time=0,change;
    string new_s="";
    do{
        change=0;
        time+=partition(s,0,change,new_s);                     //partition runs for every one second
        s=new_s;
        cout<<s<<endl;
        new_s="";
        cout<<time<<endl;
        if(change==0)
            break;
    }while(change>0);

    return time;
}
int partition(string s,int idx,int& change,string& new_s){           //"0110101"
    if(idx==s.length() || idx==s.length()-1){
        if(change>0)
            return 1;
        return 0;
    }
    if(s.substr(idx,2)=="01"){
        new_s=s.substr(0,idx)+"10"+s.substr(idx+2);
        idx+=2;
        change=1;
    }
    else{
        idx++;
        new_s=s;
    }
    return partition(new_s,idx,change,new_s);
}
string shiftingLetters(string s, vector<vector<int>>& shifts){
    for(int i=0;i<shifts.size();i++){
        s=form_words(s,shifts[i][0],shifts[i][1],shifts[i][2]);
        // cout<<s<<endl;
    }
    return s;
}
string form_words(string word,int start,int end,int type){
    if(type==0){
        // cout<<"Perform BS"<<start<<end<<endl;
        for(int i=start;i<=end;i++)
            word=backward_shift(word,i);
    }
    else{
        // cout<<"Perform FS"<<start<<end<<endl;
        for(int i=start;i<=end;i++)
            word=forward_shift(word,i);
    }
    // cout<<word<<endl;
    return word;
}
string backward_shift(string word,int idx){
    string new_word;
    if(word[idx]-(1+97)<0){
        new_word=word.substr(0,idx)+alphabets[alphabets.size()+(word[idx]-(1+97))]+word.substr(idx+1);
    }
    else{
        new_word=word.substr(0,idx)+alphabets[(word[idx]-(1+97))]+word.substr(idx+1);
    }
    word=new_word;
    return word;
    // cout<<"backward shift word:"<<word<<endl;
}
string forward_shift(string word,int idx){
    string new_word;
    if(word[idx]+1>122){
        new_word=word.substr(0,idx)+alphabets[word[idx]-122]+word.substr(idx+1);
    }
    else{
        new_word=word.substr(0,idx)+alphabets[word[idx]+1-97]+word.substr(idx+1);
    }
    word=new_word;
    return word;
    // cout<<"forward shift word:"<<word<<endl;
}
