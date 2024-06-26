#include<bits/stdc++.h>
using namespace std;

int longestcommonsubsequencehelper(string &s1,string &s2,int index1,int index2,vector<vector<int>>&dp){

    if(index1<0 || index2<0){
        return 0;
    }

    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }

    if(s1[index1]==s2[index2]){
        return 1+longestcommonsubsequencehelper(s1,s2,index1-1,index2-1,dp);
    }
    else{
        return 0+max(longestcommonsubsequencehelper(s1,s2,index1-1,index2,dp),longestcommonsubsequencehelper(s1,s2,index1,index2-1,dp));
    }

}

int longestcommonsebsequences(string s1,string s2){

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));
    return longestcommonsubsequencehelper(s1,s2,n-1,m-1,dp);
    

}

int main(){

    string s1="acd";
    string s2="ced";

    cout<<"the length of longest common subsequence is: "<<longestcommonsebsequences(s1,s2)<<endl;


    return 0;
}