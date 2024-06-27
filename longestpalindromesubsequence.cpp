/*
s="bbbab"
subsequence:-(ab,bb,bbb,bbbb,bab)
where ab is not palindrome and out of rest bbbb is largest palindrome
1.recursive(check all and pick longest)
2.power set
we can use lcs  
s="bbabcbcab" straight fashion
babcbab longest 
let write in reverse order: bacbcbabb
if some portion is common in both the string it is common subsequence
*/

#include<bits/stdc++.h>
using namespace std;

int longestcommonsubsequence(string S1,string S2 ){
    int n=S1.size();
    int m=S2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
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

int main(){

    string S1="bbabcbcab";

    cout<<"the length of longest palindrome subsequence is: "<<longestpalindromesubsequence(S1)<<endl;


    return 0;
}