/*
two operations are used either insertion or deletion
S1="abcd"            S2="anc"
delete=4
insert=3     
max(ndelete+minsert) 
abcd====anc
1.delete b d=2
2.insert n=1
what not to look  that are matched  
deletion=length of string-lcs length
insertion=m-len(lcs)
toatal=n+m-2*lcs*/
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



int Convertstring(string S1,string S2){

    int lengthofstring1=S1.size();
    int lengthofstring2=S2.size();
    int twicelenghtoflcs=2*longestcommonsubsequence(S1,S2);

    int minimumoperation=(lengthofstring1+lengthofstring2)-twicelenghtoflcs;
}

int main(){

    string S1="abcd";
    string S2="anc";

    


    cout<<"Number of deletion and insertion to convert string1 to string2: "<<Convertstring(S1,S2)<<endl;

    


    return 0;
}