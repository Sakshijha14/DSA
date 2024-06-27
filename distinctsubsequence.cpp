#include<bits/stdc++.h>
using namespace std;


const int prime=1e9+7;


int subsequenceOccuring(string S1,string S2,int n,int m){


    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){

    string S1="babgbag";
    string S2="bag";

    cout<<"Number of occurence is: "<<subsequenceOccuring(S1,S2,S1.size(),S2.size())<<endl;


    return 0;
}