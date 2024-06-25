#include<bits/stdc++.h>
using namespace std;

int countwaysfunction(vector<int> &arr,int index,int target,vector<vector<int>> &dp){

    if(index==0){
        if(target%arr[0]==0)
            return 1;
        else
            return 0;
    }
    if(dp[index][target]!=-1)
        return dp[index][target];
    int not_taken=countwaysfunction(arr,index-1,target,dp);
    int taken=0;
    if(arr[index]<=target)
        taken=countwaysfunction(arr,index,target-arr[index],dp);
    
    return dp[index][target]=not_taken+taken;
}


int countways(vector<int> &arr,int n,int target){

    vector<vector<int>> dp(n,vector<int>(target+1,-1));

    return countwaysfunction(arr,n-1,target,dp);
}

int main(){

    vector<int> arr={1,2,3};

    int target=4;

    int n=arr.size();


    cout<<"the total number of ways is: "<<countways(arr,n,target)<<endl;



    return 0;
}