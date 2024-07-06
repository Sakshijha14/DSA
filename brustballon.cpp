#include<bits/stdc++.h>
using namespace std;

int maxCoinshelper(int i,int j,vector<int>&ballon){

    if(i>j){
        return 0;
    }

    int maxi=INT_MIN;

    for(int index=i;index<=j;index++){
        int costobtained=ballon[i-1]*ballon[index]*ballon[j+1]+maxCoinshelper(i,index-1,ballon)+maxCoinshelper(index+1,j,ballon);
        
        maxi=max(maxi,costobtained);
    }
    return maxi;
}

int maxCoins(vector<int>&ballon){

    int n=ballon.size();

    ballon.insert(ballon.begin(),1);
    ballon.push_back(1);

    return maxCoinshelper(1,n,ballon);
}

int main(){

    vector<int>ballon={3,1,5,8};
    int maxCoinsoutput=maxCoins(ballon);
    cout<<"maximum coins obtained"<<maxCoinsoutput<<" "<<endl;


    return 0;
}