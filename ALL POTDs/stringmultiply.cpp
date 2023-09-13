#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string multiplystrings(string s1, string s2);
string prodof2strings(string,string);
void addnumbers(string add1,string& ans);

int main(){
    string s1="0000033",s2="2";
    cout<<multiplystrings(s1,s2);
    return 0;
}
string multiplystrings(string s1, string s2){
       string m1,m2,ans;
       int n1=s1.length(),n2=s2.length(),idx=0;
       char sign_s1='+',sign_s2='+';

       //check the sign
        if(s1[0]=='-'){
            sign_s1='-';
            idx=1;
        }
       //find index where from starts nonzero digits
       while(idx<n1 and s1[idx]=='0'){
           idx++;
       }
       if(idx==n1){                     //means one of the multiplicand must be 0
            return "0";
       }
       for(int i=idx;i<n1;i++){
           m1+=s1[i];
       }

        idx=0;
        if(s2[0]=='-'){
            sign_s2='-';
            idx=1;
        }
            
       while(idx<n2 and s2[idx]=='0'){
           idx++;
       }
       if(idx==n2){                         //means one of the multiplicand must be 0
            return "0";
       }
       for(int i=idx;i<n2;i++){
           m2+=s2[i];
       }

       //m1,m2 contains multiplicands without 0s at the front and m1 must always contain the larger integer
       if(m2.length()>m1.length()){
           swap(m1,m2);
       }
       //now we multiply strings in the usual way
       ans=prodof2strings(m1,m2);

       if(ans[0]=='0'){
            string new_ans=ans.substr(1);
            ans=new_ans;
       }

       if((sign_s1=='-' and sign_s2=='+') or (sign_s2=='-' and sign_s1=='+')){
            ans='-'+ans;
       }
       return ans;
}
string prodof2strings(string m1,string m2){
    vector<string> prodlevelres;
    
    for(int i=m2.length()-1;i>=0;i--){
        string ans;
        int carry=0;
        
        for(int j=m1.length()-1;j>=0;j--){
            int num=carry+(m1[j]-'0')*(m2[i]-'0');
            carry=num/10;
            ans+=(num%10)+'0';
        }
        if(carry){
            ans+=carry+'0';
        }
        reverse(ans.begin(),ans.end());
        // cout<<ans<<endl;
        //we append 0s equal to index at the end of results starting at index=1 to end
        for(int k=0;k<m2.length()-(i+1);k++)
            ans+='0';

        prodlevelres.push_back(ans);
    }

    //populate our ans with 0s equal to 1 more than the number of digits present in the largest product level result
    string ans;
    for(int i=0;i<prodlevelres[prodlevelres.size()-1].length()+1;i++)
        ans+='0';

    for(int i=prodlevelres.size()-1;i>=0;i--){
        addnumbers(prodlevelres[i],ans);
    }
    return ans;
}
void addnumbers(string add1,string& ans){
    int carry=0;
    int diff=ans.length()-add1.length();
    
    for(int i=add1.length()-1;i>=0;i--){
        int num=(ans[i+diff]-'0')+(add1[i]-'0')+carry;
        ans[i+diff]=(num%10)+'0';
        carry=num/10;
    }
    
    for(int i=diff-1;i>=0;i--){
        int num=(ans[i]-'0')+carry;
        ans[i]=(num%10)+'0';
        carry=num/10;
    }
}