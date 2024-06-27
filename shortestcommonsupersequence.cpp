/*
S1="brute"         S2="groot"
  common supersequence:="brutegroot"   length=10
shortest common supersequence:="bgruoote" length=8
common one taken once 
lengthof shortestsupersequence=n+m-len(lcs)
print string
      g r o o t
    0 1 2 3 4 5
  0 0 0 0 0 0 0 
b 1 0 0 0 0 0 0
r 2 0 0 1 1 1 1
u 3 0 0 1 1 1 1
t 4 0 0 1 1 1 2
e 5 0 0 1 1 1 2
perform lcs and reverse the string

*/

#include<bits/stdc++.h>
using namespace std;

int longestcommonsubsequence(string S1,string S2){

    int n=S1.size();
    int m=S2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int index1=1;index1<=n;index1++){
        for(int index2=1;index2<=m;index2++){
            if(S1[index1-1]==S2[index2-1]){
                dp[index1][index2]=1+dp[index1-1][index2-1];
            }
            else{
                dp[index1][index2]=0+max(dp[index1-1][index2],dp[index1][index2-1]);
            }
        }
    }
    return dp[n][m];
}



int shortestsupersequence(string S1,string S2){

    int Lengthofstring1=S1.size();
    int Lengthofstring2=S2.size();

    int lengthofsubsequence=longestcommonsubsequence( S1, S2);

    int shortestsupersequencelength=Lengthofstring1+Lengthofstring2-(lengthofsubsequence);
    return shortestsupersequencelength;

}


string shortestsupersequenceprint(string S1,string S2){

     int n=S1.size();
    int m=S2.size();

    int lengthofsubsequence=longestcommonsubsequence(S1,S2);

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    int i=n;
    int j=m;

    int index=lengthofsubsequence-1;
    string answer="";

    while(i>0 && j>0){
        if(S1[i-1]==S2[j-1]){
            answer[index]=S1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            answer+=S1[i-1];
            i--;
            
        }
        else{
            answer+=S2[j-1];
            j--;
        }
    }

    while(i>0){
        answer+=S1[i-1];
        i--;
    }
    while(j>0){
        answer+=S2[j-1];
        j--;
    }

    reverse(answer.begin(),answer.end());

    return answer;

}
int main(){

    string S1="brute";
    string S2="groot";


    cout<<"the shortest commom supersequence is: "<<shortestsupersequence(S1,S2)<<endl;
    cout<<"the string is : "<<shortestsupersequenceprint(S1,S2)<<endl;

    return 0;
}