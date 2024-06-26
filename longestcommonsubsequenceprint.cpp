/*
0 1 2 3 4 5
0 0 0 0 0 0 0
    b d g e k
1 0 a 0 0 0 0 0
2 0 b 1 1 1 1 1
3 0 c 1 1 1 1 1
4 0 d 1 2 2 2 2
5 0 e 1 2 2 3 3*/


#include<bits/stdc++.h>
using namespace std;

int longestcommonsubsequenceprinthelper(string &s1,string &s2,int index1,int index2,vector<vector<int>>&dp){

    if(index1<=0 || index2<=0){
        return 0;
    }

    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    if(s1[index1-1]==s2[index2-1]){
        return dp[index1][index2]=1+longestcommonsubsequenceprinthelper(s1,s2,index1-1,index2-1,dp);
    }
    else{
        return dp[index1][index2]=max(longestcommonsubsequenceprinthelper(s1,s2,index1-1,index2,dp),longestcommonsubsequenceprinthelper(s1,s2,index1,index2-1,dp));
    }    
    
}


void longestcommonsubsequenceprint(string s1,string s2){

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int length=longestcommonsubsequenceprinthelper(s1,s2,n,m,dp);

    int i=n;
    int j=m;

    int index=length-1;


    string str(length,'$');

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            str[index]=s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<str;
    

}

int main(){

    string s1="abcde";
    string s2="bdgek";


    cout<<"the longest common subsequence is: ";
    longestcommonsubsequenceprint(s1,s2);
    


    return 0;
}