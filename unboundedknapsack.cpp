#include<bits/stdc++.h>
using namespace std;

int knapsackhelper(int index,int W,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){

    if(index==0){
        return (W/wt[0])*val[0];
    }

    if(dp[index][W]!=-1)
        return dp[index][W];

    int not_taken=0+knapsackhelper(index-1,W,val,wt,dp);
    int taken=INT_MIN;

    if(wt[index]<=W){
        taken=val[index]+knapsackhelper(index,W-wt[index],val,wt,dp);
    }
    return dp[index][W]=max(not_taken,taken);
}

int unbounded(int n,int W,vector<int>&val,vector<int>&wt){

    vector<vector<int>>dp(n,vector<int>(W+1,-1));

    return knapsackhelper(n-1,W,val,wt,dp);
}

int main(){

    vector<int>wt={2,4,6};
    vector<int>val={5,11,13};
    int W=10;
    int n=wt.size();

    cout<<"the maximum value of items the theif can steal is: "<<unbounded(n,W,val,wt)<<endl;



    return 0;
}