/*
we need to know lcs,longest palindromic subsequence
we can insert any character anywhere 
      S="abcaa"
reverse="aacba"
just add in reverse of it for max in length 
minimum we need 
s="aabcbaa"
to make it insertion it need is 2 
palindrome portion=a,aa,aaa,aba
keep longest palindrome portion for minimum
a bc a bc a:=a bc a cb a
2 have no matching  put non match in reverse order
coding ninja 
codi sajn ingni njas idoc 
minimum insertion=length of string -length palindrome subsequence */

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

int longestpalindromesubsequence(string S1){
    
    string reversestring=S1;

    reverse(S1.begin(),S1.end());

    return longestcommonsubsequence(S1,reversestring);
}

int minimuminsertion(string S1){

    int sizeofS1=S1.size();

    int minimuminsert=sizeofS1-longestpalindromesubsequence(S1);

    return minimuminsert;


}

int main(){

   string S1="abcaa";

   cout<<"the minimum insertion needed is: "<<minimuminsertion(S1)<<endl;

    return 0;
}