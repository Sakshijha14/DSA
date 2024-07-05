#include<bits/stdc++.h>
using namespace std;

int matrixMultiplicationhelper(vector<int>&arr,int i,int j){

    if(i==j){
        return 0;
    }

    int mini=INT_MAX;

    for(int k=i;k<=j-1;k++){

        int numberofsteps=matrixMultiplicationhelper(arr,i,k)+matrixMultiplicationhelper(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];

        mini=min(numberofsteps,mini);
        
    }
    return mini;
}

int matrixMultiplication(vector<int>&arr,int n){

    int i=1;
    int j=n-1;

    return matrixMultiplicationhelper(arr,i,j);
}

int main(){

    vector<int>arr={10,20,30,40,50};
    int n=arr.size();

    cout<<"the minimum number of operation is "<<matrixMultiplication(arr,n);




    return 0;
}