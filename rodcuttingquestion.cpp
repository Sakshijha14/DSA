#include<bits/stdc++.h>
using namespace std;


int rodproblemhelper(int index,int N,vector<int>&price,vector<vector<int>> &dp){
    if(index==0){
        return N*price[0];
    }
    
    if(dp[index][N]!=-1){
        return dp[index][N];
    }

    int not_taken=0+rodproblemhelper(index-1,N,price,dp);
    int taken=INT_MIN;

    if(price[index]<=N){
        taken=rodproblemhelper(index,N-price[index],price,dp);
    }
    return dp[index][N]=max(not_taken,taken);
}
int Rodcutting(vector<int>&price,int n){
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    return rodproblemhelper(n-1,n,price,dp);
}

int main(){

    int N=5;
    vector<int> price={2,5,7,8,10};
    int n=price.size();
    cout<<"the maximum price will be breaking the rod is: "<<Rodcutting(price,n)<<endl;


    return 0;
}