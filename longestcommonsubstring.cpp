/*
Longest common substring
S1="abcjklp"   S2="acjkp"
substring:-it is concecutive cjk length 3
subsequence:-acjkp

not matching not work in substring: because as shinkring string considering ommiting one portion
abcd    abzd
subseq:-abd
substr:-ab
      a b z d
    0 1 2 3 4
  0 0 0 0 0 0
a 1 0 1 0 0 0
b 2 0 0 2 0 0 //since it is concecutive so not depended on previous one
c 3 0 0 0 0 0
d 4 0 0 0 0 1//if previous diagonal is match then val + 1
*/
#include<bits/stdc++.h>
using namespace std;




int longestcommonsubstring(string S1,string S2){

    int n=S1.size();
    int m=S2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
    for(int index2=0;index2<=m;index2++){
        dp[0][index2]=0;
    }
    for(int index1=0;index1<=n;index1++){
        dp[index1][0]=0;
    }
    int answer=0;

    for(int index1=1;index1<=n;index1++){
        for(int index2=1;index2<=m;index2++){
            if(S1[index1-1]==S2[index2-1]){
                dp[index1][index2]=1+dp[index1-1][index2-1];
                answer=max(answer,dp[index1][index2]);
            }
            else{
                dp[index1][index2]=0;
            }
        }
    }
    return answer;
}

int main(){

    string S1="abcjklp";
    string S2="acjkp";

    cout<<"the longest common substring: "<<longestcommonsubstring(S1,S2)<<endl;


    


    return 0;
}